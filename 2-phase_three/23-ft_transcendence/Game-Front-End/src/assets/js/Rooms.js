

const CreateRoomFormDataIds = {
    nickname: 'nickname-input',
    gameType: 'game-type-section',
    numberOfPlayers: 'number-of-players-section',
    roomName: 'room-name-input',
    isPrivate: 'private-room-checkbox'
}

async function CreateRoomAsync(event, document, window) {
    event.preventDefault();
    const formRoomData = {
        createdBy: document.getElementById(CreateRoomFormDataIds.nickname).value,
        roomType: document.getElementById(CreateRoomFormDataIds.gameType).value,
        maxAmountOfPlayers: document.getElementById(CreateRoomFormDataIds.numberOfPlayers).value,
        roomName: document.getElementById(CreateRoomFormDataIds.roomName).value,
        privateRoom: document.getElementById(CreateRoomFormDataIds.isPrivate).checked
    };
    const response = await RoomRepository.PostCreateRoomAsync(formRoomData)
    if (response.status === true) {
        await redirectHrefRoom(window, response.data.roomCode, response.data.roomType)
    }
}

async function ShowRooms(filters, document) {
    const response = await RoomRepository.GetRoomsAsync(filters, document);
    if (response.status === true) {
        const data = response.data;
        let paginatedGroup = document.getElementById("paginated-list-rooms");
        RoomPaginationComponent(paginatedGroup, data, "listRooms");

        let rooms = data["paginatedItems"]["Data"];
        const listGroup = document.getElementById('rooms-list');
        listGroup.innerHTML = ""
        rooms.forEach(room => {
            const listItem = ShowRoomItemComponent(room);
            addCopyButtonEvent(listItem);
            listGroup.appendChild(listItem);
        });
    }
}

async function AddToRoomAsync(event, window) {
    event.preventDefault();
    const formData = {
        playerName: event.target.elements['nickname-input'].value,
        roomCode: event.target.elements['room-name-input'].value
    };
    const response = await RoomRepository.PutAddToRoomAsync(formData);
    if (response.status === true) {
        await redirectHrefRoom(window, response.data.roomCode, response.data.roomType)
    }
}

async function redirectHrefRoom(window, roomCode, roomType) {
    let pathName = roomType === 1 ?
        `${RouteNames["tournament"]}` :
        `${RouteNames["match"]}` ;
    window.routes.updateRoomCode(roomCode)
    await DOMRender(pathName)
}

async function redirectGame(gameId) {
    let pathName = `${RouteNames["game"]}`
    window.routes.updateGameId(gameId)
    await DOMRender(pathName)
}

// Ajustar para o novo modelo de retorno
function GetPlayerColor(code) {
    return PlayerColor[code]
}

function addCopyButtonEvent(listItem) {
    const copyButton = listItem.querySelector('.copy-btn');
    copyButton.addEventListener('click', (event) => {
        event.preventDefault();
        const roomCode = copyButton.getAttribute('data-room-code');

        navigator.clipboard.writeText(roomCode).then(() => {
            const toastBody = document.querySelector('#roomCodeToast .toast-body');
            toastBody.textContent = `Room code "${roomCode}" copied to clipboard!`;

            const toastElement = document.getElementById('roomCodeToast');
            const toast = new bootstrap.Toast(toastElement);
            toast.show();
        }).catch((error) => {
            console.error(`Failed to copy room code: `, error);
        });
    });
}

function updateNumberOfPlayersOptions() {
    const gameTypeSelect = document.getElementById("game-type-section");
    const playersSelect = document.getElementById("number-of-players-section");

    const selectedGameType = gameTypeSelect.value;
    playersSelect.innerHTML = ""
    playersSelect.disabled = false
    let options = [];
    if (selectedGameType === "0") {
        options = [2, 4];
    } else if (selectedGameType === "1") {
        options = [4];
    } else if (selectedGameType === "2") {
        options = [1];
        playersSelect.disabled = true;
    }

    let i = 0
    options.forEach(optionValue => {
        const optionElement = document.createElement("option");
        if (i == 0)
            optionElement.selected = true
        optionElement.value = optionValue;
        optionElement.textContent = optionValue;
        playersSelect.appendChild(optionElement);
        i++
    });
}

async function listRooms(currentPage = 1, pageSize = 5) {
    filterLabel = document.getElementById("search-input-filter-room").value;
    await ShowRooms({ currentPage, pageSize, filterLabel }, document);
}

async function addToRoom(event) {
    event.preventDefault();
    await AddToRoomAsync(event, window);
}

filterLabel = ""
async function listRanking(currentPage = 1, pageSize = 10) {
    filterLabel = document.getElementById("search-input-filter-room").value;
    await ShowRanking({ currentPage, pageSize, filterLabel }, document);
}

function	getPlayer(gameId) {
    fetch(`/api/v1/user-session/players/game/${gameId}/`, {
            method: 'GET',
        })
            .then(response => response.json())
            .then(data => {
                const playerListElement = document.getElementById("list-of-players")

                playerListElement.innerHTML = ""
                players = data["players"]
                players.sort((a, b) => a.profileColor - b.profileColor);
                players.forEach(player => {
                    const playerElement = document.createElement('div');
                    playerElement.classList.add("list-group-item", "list-group-item-action", "py-3", "lh-sm", "rounded-4", "mb-2")
                    let [r, g, b, a] = PlayerColor[player.profileColor]
                    playerElement.innerHTML = `
                        <div class="d-flex w-100 align-items-center justify-content-between">
                            <div class=" d-flex w-75 align-items-center">
                                <img style='background-color: rgba(${r}, ${g}, ${b}, ${a / 100})' class="rounded-circle img-thumbnail" src="${player.urlProfileImage}" alt="">
                                <div class="d-flex flex-column  ps-2 justify-content-center">
                                    <strong class="mb-1">${player.name}</strong>
                                    <p class="small mb-0">${PlayerColorLabel[player.profileColor]}</p>
                                </div>
                            </div>
                            <h3 id="player-${player.profileColor}" class="text-body-secondary">${player.score}</h3>
                        </div>
                        `;
                    playerListElement.appendChild(playerElement)
                });
            })
}