function ShowRoomItemComponent(room) {
    const listItem = document.createElement('div');
    listItem.classList.add('list-group-item', 'py-3', 'lh-sm');

    listItem.innerHTML = `
        <div class="d-flex w-100 align-items-center justify-content-between">
            <button class="bi bi-copy btn btn-sm btn-outline-primary copy-btn" data-room-code="${room["roomCode"]}">
            </button>
            <div class="w-75">
                <strong class="mb-1">${gameTypes[room["roomType"]]}: ${room["roomName"]}</strong>
                <div class="col-10 mb-1 small">Code: ${room["roomCode"]}</div>
            </div>
            <small class="text-body-secondary">${room["amountOfPlayers"]}/${room["maxAmountOfPlayers"]}</small>
        </div>
    `;

    return listItem;
}

function RemovePlayerComponent (data, player, createdBy) {
    return (player.id == createdBy) ?
    "<small class='text-body-secondary bi bi-person'> Owner</small>" :
    (data["isOwner"] ?
        `<h1 class='modal-handler p-0 btn-remove-player h3 pe-2 bi bi-x-circle' data-target="alert-remove-player-modal" data-player-id="${player.id}"></h1>` :
        "");
}

function PlayerLabelComponent(data, player, createdBy, roomType) {
    let element = document.createElement('div')
    element.classList.add("list-group-item", "list-group-item-action", "py-3", "lh-sm", "rounded-4", "mb-2")

    let [r, g, b, a] = PlayerColor[player.profileColor]
    let rgbaPlayerColor = `style='background-color: rgba(${r}, ${g}, ${b}, ${a / 100})'`
    let owner = ""
    let you = player.you ? " | You" : ""

    if (roomType != 2) {
        owner = RemovePlayerComponent(data, player, createdBy)
    }

    element.innerHTML = `
        <div class="d-flex w-100 align-items-center justify-content-between">
            <div class=" d-flex w-75 align-items-center">
                <img ${rgbaPlayerColor} src="${player.urlProfileImage}" class="rounded-circle img-thumbnail" alt="">
                <div class="d-flex flex-column  ps-2 justify-content-center">
                    <strong class="mb-1">${player.name}</strong>
                    <p class="small mb-0">${PlayerColorLabel[player.profileColor]}${you}</p>
                </div>
            </div>
            ${ owner }
        </div>
    `
    return element
}

function NonePlayerLabelComponent() {
    const element = document.createElement('div');
    element.classList.add("disabled", "list-group-item", "list-group-item-action", "py-3", "lh-sm", "rounded-4", "mb-2", "bg-secondary")
    element.innerHTML = `
        <div class="d-flex w-100 align-items-center justify-content-between">
            <div class="d-flex w-75 align-items-center">
                <img class="rounded-circle img-thumbnail" src="./assets/img/none.png" alt="">
                <div class="d-flex flex-column  ps-2 justify-content-center">
                    <strong class="mb-1"></strong>
                    <p class="small mb-0"></p>
                </div>
            </div>
        </div>
        `;
    return element
}

function MatchPlayerListComponent(data) {
    players = data["players"]
    createdBy = data["createdBy"]
    roomType = data["roomType"]

    const playerListElement = document.getElementById("list-of-players")
    playerListElement.innerHTML = ""

    let i = 0;
    players.forEach(player => {
        let playerElement = PlayerLabelComponent(data, player, createdBy, roomType)
        playerListElement.appendChild(playerElement)
        i++;
    });

    while (i < data.maxAmountOfPlayers)
    {
        let nonePlayerElement = NonePlayerLabelComponent()
        playerListElement.appendChild(nonePlayerElement)
        i++;
    }
}

function MatchGameInformationComponent(data) {
    const roomNameElement = document.getElementById("room-name")
    roomNameElement.innerHTML = `
        <div>
            <h1>${GamesType[data["roomType"]]}: ${data["roomName"]}</h1>
            <p>It will be possible to start the match as soon as there is the minimum number of players.</p>
        </div>
        `
}

function CloseRoomButtonComponent(data) {
    return  `<p class="lead px-3">
                <a data-room-code="${data["roomCode"]}" data-target="alert-close-room-modal" class="btn modal-handler btn-lg btn-secondary">Close Room</a>
            </p>`
 }

function StartGameButttonComponent() {
    return `<p class="lead px-3">
                <button type="button" class="btn btn-start-game btn-lg btn-dark">Start Game</button>
            </p>`
}

function LeaveRoomButtonComponent(userId) {
    return `
        <p class="lead px-3">
            <button data-player-code="${userId}" data-target="alert-leave-room-modal" class="btn modal-handler btn-lg btn-secondary">Leave Room</button>
        </p>
        `
}

function MatchActionsComponent(data)
{
    let element = document.getElementById("room-actions")
    let btnSection = LeaveRoomButtonComponent(data)

    if (data["isOwner"])
    {
        btnSection = `
        ${CloseRoomButtonComponent(data)}
        ${StartGameButttonComponent()}
        `
    }

    element.innerHTML = `
    <a class="w-75 bi bi-copy btn btn-dark copy-btn" data-room-code="${data["roomCode"]}"> Room Code: ${data["roomCode"]}</a>
    <div class="d-flex align-items-end
    ">
        ${btnSection}
    </div>
    `
    addCopyButtonEvent(document);
}

function MatchRoomComponent(data) {
    MatchGameInformationComponent(data)
    MatchPlayerListComponent(data)
    MatchActionsComponent(data)
}

function PlayerLabelTournamentComponent(player, index)
{
    let element = document.createElement("div")
    element.classList.add("list-group-item", "list-group-item-action", "py-2", "lh-sm", "rounded-4", "mb-1")
    if (player === null)
        element.classList.add("bg-dark", "text-white")
    let you = player ? player.you ? "<p class='small mb-0'>You</p>" : "" : ""
    let [r, g, b, a] = player ? PlayerColor[player.color] : [0, 0, 0, 0];
    element.innerHTML = `
        <div class="d-flex w-100 align-items-center justify-content-between">
            <div class="d-flex w-100 align-items-center">
                <img class="rounded-circle img-thumbnail" style="background-color: rgba(${r}, ${g}, ${b}, ${a / 100})" src="${ player === null ? "/assets/img/none.png" : player["urlProfileImage"]}" alt="">
                <div class="d-flex flex-column ps-2 justify-content-center">
                    <strong class="mb-1">${ player === null ? "None" : player["name"]}</strong>
                    ${player === null ? "<p class='small mb-0'>waiting</p>" : you}
                </div>
            </div>
            <h3 class="ps-3 text-body-secondary">${index}</h3>
        </div>
    `
    return element
}

function BracketsRowsComponent(data) {
    let tournamentList = document.getElementById("tournament-brackets");
    let brackets = document.createElement("div")
    let bracketsRow = document.createElement("div")

    tournamentList.innerHTML = ""

    let step = TournamentConfig["amountPlayersByBracketsRow"]
    let players = data["players"]
    for (i = 1; i <= data["maxNumberOfPlayers"]; i++) {

        let playerElement = PlayerLabelTournamentComponent(players[`${i}`], i)
        brackets.appendChild(playerElement)
        if (i % TournamentConfig["amountPlayersByBrackets"] === 0) {
            brackets.classList.add("my-2")
            bracketsRow.appendChild(brackets)
            brackets = document.createElement("div")
        }

        if (i === step || (data["maxNumberOfPlayers"] === 2 && i === 2)) {
            bracketsRow.classList.add("w-100", "d-flex", "flex-row", "justify-content-around")
            tournamentList.appendChild(bracketsRow)
            bracketsRow = document.createElement("div")
            step += TournamentConfig["amountPlayersByBracketsRow"]
        }
    }
}

function TournamentInformationComponent(data) {
    const tournamentInfo = document.getElementById("tournament-info")
    tournamentInfo.classList.add("w-100", "d-flex", "pb-5", "flex-row", "justify-content-start")
    tournamentInfo.innerHTML = ""
    tournamentInfo.innerHTML = `
        <div class="pe-4 border-end border-dark border-3">
            <h1 class="mb-0" style="font-size: 65px">${data["numberOfPlayers"]}/${data["maxNumberOfPlayers"]}</h1>
            <p class="mb-0">players in tournament</p>
        </div>
        <div class="ps-4 me-5">
            <h1>${GamesType[data["roomType"]]}: ${data["roomName"]}</h1>
            <p>It will be possible to start the match as soon as there is the minimum number of players.</p>
        </div>
        <a class="bi bi-copy btn btn-dark copy-btn" style="height: 35px; line-height: 35px; padding: 0 10px;" data-room-code="${data["roomCode"]}"> Room Code: ${data["roomCode"]}</a>
    `
    addCopyButtonEvent(tournamentInfo);
}

async function TournamentActionsComponent(data, roomCode) {
    let elementActions = document.getElementById("tournament-action")
    elementActions.classList.add("h-100", "d-flex", "flex-column", "align-items-end", "justify-content-end")
    elementActions.innerHTML = ""
    let historyList = await TournamentHistoryComponent(roomCode)
    elementActions.appendChild(historyList)

    if (data["tournamentOwner"] && data["round"] == 1 && data["roomStatus"] != 3)
    {
        let btnSection = document.createElement("div")
        btnSection.classList.add("d-flex", "justify-content-end", "w-100")
        btnSection.innerHTML = `
            <button type="button" class="btn btn-lock-tournament btn-lg btn-dark me-2">Lock Tournament</button>
            <a data-room-code="${data["roomCode"]}" data-target="alert-close-room-modal" class="btn modal-handler btn-lg btn-secondary">Close Room</a>
        `
        elementActions.appendChild(btnSection)
    }
    else if (data["round"] == 1 && data["roomStatus"] != 3)
    {
        let btnSection = document.createElement("div")
        btnSection.classList.add("d-flex", "justify-content-end", "w-100")
        btnSection.innerHTML = `
            <button data-player-code="${data}" data-target="alert-leave-room-modal" class="btn modal-handler btn-lg btn-secondary">Leave Room</button>
        `
        elementActions.appendChild(btnSection)
    }

    if ((data["owner"]) && data["roomStatus"] >= 3) {
        let btnSection = document.createElement("div")
        btnSection.classList.add("d-flex", "justify-content-end", "w-100")
        btnSection.innerHTML = `
            <button type="button" class="btn btn-start-tournament-game btn-lg btn-dark">Start Game</button>
        `
        elementActions.appendChild(btnSection)
    }
}

async function TournamentRoomComponent(data, roomCode) {
    await TournamentActionsComponent(data, roomCode)
    TournamentInformationComponent(data)
    BracketsRowsComponent(data)
}

function TournamentHistoryItemComponent(game) {
    let element = document.createElement("li")
    element.classList.add("list-group-item", "list-group-item-action", "py-2", "lh-sm", "rounded-2", "mb-1", "d-flex", "justify-content-between", "align-items-center")

    element.innerHTML = ""
    let [r, g, b, a] = PlayerColor[game["0"].color]
    let [c, d, e, f] = PlayerColor[game["1"].color]
    element.innerHTML = `
        <div class="d-flex align-items-center">
            <img class="rounded-circle img-thumbnail" style="background-color: rgba(${r}, ${g}, ${b}, ${a / 100})" src="${game["0"]["profileImage"]}" alt="" style="width: 40px; height: 40px">
            <p class="me-2 mb-0">${game["0"]["name"].slice(0, 6)}</p>
        </div>
        <div>
        <p class="mb-0">${game["0"]["score"]} X ${game["1"]["score"]}</p>
        </div>
        <div class="d-flex align-items-center">
        <p class="pe-2 mb-0">${game["1"]["name"].slice(0, 6)}</p>
            <img class="rounded-circle img-thumbnail" style="background-color: rgba(${c}, ${d}, ${e}, ${f / 100})" alt="" style="width: 35px; height: 35px">
        </div>
    `
    return element
}

async function TournamentHistoryComponent(roomCode) {
    let element = document.createElement("div")
    element.classList.add("w-100", "mb-3")

    let elementHeader = document.createElement("p")
    elementHeader.classList.add("mb-3")
    elementHeader.innerHTML = `
        <b>Games history</b>
        </br>
        <small>History of games results in this tournament.</small>
    `
    element.appendChild(elementHeader)

    let paginatedGames = await getTournamentGamesHistoryPaginated(null);
    let historyElement = document.createElement("div")
    historyElement.classList.add("list-group")
    historyElement.id = "tournament-history"
    let currentStage = 0
    paginatedGames["games"].forEach((game) => {
        stageElement = document.createElement("div")
        if (currentStage !== game['stage']) {
            stageElement.innerHTML = `<b>Round ${game['stage']}</b>`
            currentStage = game['stage']
        }
        historyElement.appendChild(stageElement)
        let item = TournamentHistoryItemComponent(game)
        historyElement.appendChild(item)
    });

    element.appendChild(historyElement)

    let paginatedHistory = document.createElement("div")
    paginatedHistory.classList.add("pagination", "mt-1", "justify-content-center")
    paginatedHistory.id = "tournament-history-pagination"
    PaginationComponent(paginatedHistory, paginatedGames, "getTournamentGamesHistoryPaginated");

    element.appendChild(paginatedHistory)

    return element
}

function AddModalComponent(
    modalName,
    description,
    icon,
    title,
    content,
    actionClass,
    yesBtnName,
    noBtnName
) {
    let modal = document.createElement("div")
    modal.classList.add("modal", "fade")
    modal.setAttribute('id', modalName);
    modal.setAttribute('tabindex', '-1');
    modal.setAttribute('role', 'dialog');
    modal.setAttribute('aria-labelledby', description);
    modal.setAttribute('aria-hidden', 'true');
    modal.innerHTML = `
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content text-center">
                <div class="modal-header align-items-start">
                    <div class="w-100">
                        <h1 class="${icon}"></h1>
                        <h4 class="modal-title" id="${modalName}-title">${title}</h4>
                    </div>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>

                <div class="modal-body">
                ${content}
                </div>

                <div class="modal-footer mb-3 w-100">
                    <button type="button" class="btn btn-lg btn-secondary" data-bs-dismiss="modal">${noBtnName}</button>
                    <button type="button" class="btn btn-lg ${actionClass} btn-dark" data-bs-dismiss="modal">${yesBtnName}</button>
                </div>
            </div>
        </div>
    `
    return modal
}
