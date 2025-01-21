const route = "rooms"

async function GetRoomsAsync(filters, document) {
    return await fetch(`${RoutesInfo.userSessionAPI}/${route}/?currentPage=${filters.currentPage}&pageSize=${filters.pageSize}&filterLabel=${filters.filterLabel}`, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json',
            'X-User-Id': getCookie(document, "userId")
        }
    })
    .then(async response => {
        if (response.ok) {
            const data = await response.json();
            return ({
                status: response.status,
                data
            });
        }
        return (ProcessErrors(response, {"title": "Error on Get Rooms", "message": "Not Found"} ))
    })
    .then(({ status, data }) => {
        return { "status": true, "data": data }
    })
    .catch(error => {
        if (error instanceof CustomError) {
            return {"status": false, "title": error.title, "message": error.message}
        } else {
            return {"status": false, "title": "Not Expected", "message": error.message}
        }
    });
}

async function PutAddToRoomAsync(FormData) {
    return await fetch(`${RoutesInfo.userSessionAPI}/${route}/${FormData.roomCode}/add-player/`, {
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(FormData)
    })
    .then(async response => {
        if (response.status === 201) {
            const userId = response.headers.get("X-User-Id");
            let data = await response.json();
            addUserIdIntoCookie(document, userId)
            return ({
                status: response.status,
                data
            });
        }
        return (ProcessErrors(response, {"title": "Error on Add To Room", "message": "Not Found"} ))
    })
    .then(({ status, data }) => {
        return { "status": true, "data": data }
    })
    .catch(error => {
        if (error instanceof CustomError) {
            return {"status": false, "title": error.title, "message": error.message}
        } else {
            return {"status": false, "title": "Not Expected", "message": error.message}
        }
    });
}

function ProcessErrors(response, error) {
    if (response.status >= 400 && response.status < 500) {
        throw new CustomError(error.title, error.message);
    } else if (response.status >= 500) {
        throw new CustomError("Erro do Servidor", `Erro ${response.status}: Tente novamente mais tarde.`);
    }
}

const APIEndPoints = {
    'user': '/api/v1/user-session/',
    'uws': '',
    'game': '/api/v1/game-core/',
}

async function CloseRoom(event, roomCode) {
    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/delete`;
    ApiRequestHandler(endpoint, 'DELETE')
        .then(async response => {
            await handleApiSuccessAsync(response, async () => {
                resetUserIdIntoCookie(document);
                await DOMRender("/home.html")
            });
        })
        .catch(handleApiError);
}

function RemovePlayerFromRoom(event, roomCode) {
    const modal = event.target.closest(".modal");
    const playerId = modal.dataset.playerId;

    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/${playerId}/remove-player/`;
    ApiRequestHandler(endpoint, 'DELETE')
        .then(response => {
            handleApiSuccess(response, () => {
                alert("Colocar um aviso de que o player saiu igual ao que aparece quando copiamos coisas.")
            })
        })
        .catch(handleApiError)
}

function StartAGame(event, roomCode) {
    const endpoint = `${APIEndPoints["user"]}games/${localStorage.getItem("roomCode")}/new-game/`;
    ApiRequestHandler(endpoint, 'POST')
        .then(response => {
            handleApiSuccess(response, () => {
                // This action ws do.
            });
        })
        .catch(handleApiError);
}

function StartATournamentGame(event, roomCode) {
    const endpoint = `${APIEndPoints["user"]}games/${localStorage.getItem("roomCode")}/new-tournament-game/`;
    ApiRequestHandler(endpoint, 'POST')
        .then(response => {
            handleApiSuccess(response, () => {
                // This action ws do.
            });
        })
        .catch(handleApiError);
}

function LeaveTheRoom(event, roomCode) {
    let userId = getCookie(document, "userId");
    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/${userId}/remove-player/`;
    ApiRequestHandler(endpoint, 'DELETE')
        .then(response => {
            handleApiSuccess(response, () => {
                alert("Colocar um aviso de que o player saiu igual ao que aparece quando copiamos coisas.")
            })
        })
        .catch(handleApiError)
}

function LockTournament(event, roomCode)
{
    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/lock-tournament/`;
    ApiRequestHandler(endpoint, 'POST')
        .then(response => {
            handleApiSuccess(response, () => {
                alert("Torneio trancado com sucesso!")
            })
        })
        .catch(handleApiError)
}

async function CreateRoom(event) {
    event.preventDefault()
    const data = {
        createdBy: event.target.nickname.value,
        roomType: event.target.gameType.value,
        maxAmountOfPlayers: event.target.numberOfPlayers.value,
        roomName: event.target.roomName.value,
        privateRoom: event.target.isPrivate.checked
    }

    const endpoint = `${APIEndPoints["user"]}rooms/new-room/`;
    await ApiRequestHandler(endpoint, 'POST', body = data)
        .then(async response => {
            handleApiSuccessAsync(response, async () => {
                const userId = response.headers.get("X-User-Id");
                const data = await response.json();
                addUserIdIntoCookie(document, userId);
                await redirectHrefRoom(window, data.roomCode, data.roomType)
            })
        })
        .catch(handleApiError)
}

async function ShowMatchRoom(roomCode) {
    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/detail`;
    await ApiRequestHandler(endpoint, 'GET')
        .then(async response => {
            await handleApiSuccessAsync(response, async () => {
                const data = await response.json();
                MatchRoomComponent(data)
            })
        })
        .catch(handleApiError)
}

async function ShowTournamentRoom(roomCode) {
    const endpoint = `${APIEndPoints["user"]}rooms/${localStorage.getItem("roomCode")}/tournament/`;
    await ApiRequestHandler(endpoint, 'GET')
        .then(async response => {
            await handleApiSuccessAsync(response, async () => {
                const data = await response.json();
                await TournamentRoomComponent(data, localStorage.getItem("roomCode"))
            })
        })
        .catch(handleApiError)
}

async function getTournamentGamesHistoryPaginated(event) {
    let endpoint = `${APIEndPoints["game"]}games/tournament-history/?roomCode=${localStorage.getItem("roomCode")}`;
    return await ApiRequestHandler(endpoint, 'GET')
        .then(async response => {
            let data = await handleApiSuccessAsync(response, async () => {
                const data = await response.json();
                return data;
            });
            return data;
        })
        .catch(handleApiError);
}

function ShowTournamentGamesHistory(event) {
    const roomCode = event.target.dataset.roomCode;
    const page = event.target.dataset.page;
    getTournamentGamesHistoryPaginated(event)
    .then(paginatedGames => {
        let historyElement = document.getElementById("tournament-history");
        historyElement.innerHTML = "";
        paginatedGames["data"].forEach(game => {
            let item = TournamentHistoryItemComponent(game)
            historyElement.appendChild(item)
        });

        let paginatedHistory = document.getElementById("tournament-history-pagination");
        paginatedHistory.innerHTML = "";
        PaginationComponent(paginatedHistory, paginatedGames, "listRooms");
    });
}

const RoomRepository = {
    // Player Actions
    CloseRoom,
    LeaveTheRoom,
    RemovePlayerFromRoom,
    StartAGame,
    StartATournamentGame,

    CreateRoom,
    ShowMatchRoom,
    ShowTournamentRoom,

    GetRoomsAsync,
    PutAddToRoomAsync
}