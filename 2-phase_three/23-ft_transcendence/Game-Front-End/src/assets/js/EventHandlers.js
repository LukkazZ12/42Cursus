const btnActions = {
    "btn-close-room": CloseRoom,
    "btn-remove-player": RemovePlayerFromRoom,
    "btn-start-game": StartAGame,
    "btn-start-tournament-game": StartATournamentGame,
    "btn-leave-the-room": LeaveTheRoom,
    "btn-lock-tournament": LockTournament,
};

const btnPageActions = {
    "btn-open-list-rooms" : DOMRender,
    "btn-brand-icon": DOMRender,
}

async function HandleEvents(event, roomCode) {
    if (event.target.matches(".modal-handler")) {
        event.preventDefault()
        const targetModalId = event.target.dataset.target;
        const modalElement = document.getElementById(targetModalId);
        const playerId = event.target.dataset.playerId;

        modalElement.dataset.playerId = playerId;

        var modal = new bootstrap.Modal(modalElement);
        modal.show();
        return
    }
    if (event.target.dataset.pageName) {
        event.preventDefault()
        await DOMRender(event.target.dataset.pageName);
        return;
    }
    if (event.target.matches(".btn") || event.target.matches(".act")) {
        for (const [className, action] of Object.entries(btnActions)) {
            if (event.target.classList.contains(className)) {
                event.preventDefault()
                action(event, roomCode);
                return;
            }
        }
    }
}

class PageHome {
    async init() {
    }


    async destroy() {
    }
}

class PageViewRooms {
    async init() {
        listRooms();
    }


    async destroy() {
    }
}

class Ranking {
    async init () {
        listRanking();
    }

    async destroy() {
    }
}

class PageGame {
    constructor() {
        this.socket = null
        this.keydownHandler = null;
    }

    async init() {
        gPong = {
            time: Date.now(),
            delta: 0,
        };
        gInterface = {};
        gCanvas = document.getElementById('myCanvas');
		gl = gCanvas.getContext('webgl2');
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
        gObjects = [];
        gCamera = new Camera();
        gShader = {};
        gCtx = {
            view: mat4(),
            perspective: mat4(),
        };
        gPositions = [];
        gColors = [];
        gNormals = [];
        gTextures = [];
        doOnce = true;

        const	host = window.location.host;
        const	endpoint = `/api/v1/game-core/games/${localStorage.getItem("gameId")}/`;
		const	userId = getCookie(document, "userId");


        getPlayer(localStorage.getItem("gameId"))
        document.getElementById("canva-section").classList.remove("d-none")


        this.socket = new WebSocket(`wss://${host}${endpoint}`);
        this.keydownHandler =(event) => sendKey(event, this.socket);

        this.socket.onopen = (event) =>  {
            const headers = { "X-User-Id": getCookie(document, "userId")};
            if (this.socket !== null) {
                this.socket.send(JSON.stringify({
                    type: 'connect',
                    headers: headers
                }));
            }

            WSConnection(document, true)
        };

        document.addEventListener('keydown', (event) => {
            if (this.socket !== null) {
                const	key = event.key;
                this.socket.send(JSON.stringify({
                    direction: key,
                    headers: { "X-User-Id": userId }
                }));
            }
        });


        this.socket.onmessage = async (event) => {
            const data = JSON.parse(event.data);
            if (data.type == 'game.update') {
                drawOnCanvas(data.game_state);
            }

            if (data.type === "update_score") {
                let playerColor = data.playerColor
                let element = document.getElementById(`player-${playerColor}`)
                element.innerHTML = data.playerScore
            }

            if (data.type === "game_finished") {
                if (data.winner != userId) {
                    const gameOverLoserModal = new bootstrap.Modal(document.getElementById('gameOverLoserModal'));
                    gameOverLoserModal.show();
                    localStorage.setItem("currentPage", "/home.html")
                }
                else {
                    if (data.roomType === 1)
                        await redirectHrefRoom(window, localStorage.getItem("roomCode"), data.roomType)
                    else {
                        const gameOverWinnerModal = new bootstrap.Modal(document.getElementById('gameOverWinnerModal'));
                        gameOverWinnerModal.show();
                        localStorage.setItem("currentPage", "/home.html")
                    }
                }
            }
        };

        this.socket.onclose = function(event) {
            WSConnection(document, false)
        };

        this.socket.onerror = function(error) {
            console.error("WebSocket error:", error);
        };
    }

    async destroy() {
        document.getElementById("canva-section").classList.add("d-none")

        if (this.socket && this.socket.readyState === WebSocket.OPEN) {
            this.socket.close();
        }

        document.removeEventListener('keydown', this.keydownHandler);

        this.socket = null;
    }
}

function sendKey(event, socket)
{
    const	key = event.key;
    const	userId = getCookie(document, "userId");
    socket.send(JSON.stringify({
        direction: key,
        headers: { "X-User-Id": userId }
    }));
}

class PageMatchRoom {

    constructor() {
        this.socket = null
    }


    async init() {
        const userId = getCookie(document, "userId")
        const host = window.location.host;
        const endpoint = "/api/v1/user-session/";
        await ShowMatchRoom(localStorage.getItem("roomCode"))
        this.socket = new WebSocket(`wss://${host}${endpoint}ws/rooms/${localStorage.getItem("roomCode")}/?userId=${userId}`);

        this.socket.onopen = function(event) {
            WSConnection(document, true)
        };


        this.socket.onmessage = async (event) => {
            const data = JSON.parse(event.data);
            if (data.type == "delete_room" || (data.type == "player_list_update" && data.userRemoved == userId)) {
                resetUserIdIntoCookie(document)
                await DOMRender("/home.html")
            } else if (data.type == "player_list_update")
                await ShowMatchRoom(localStorage.getItem("roomCode"));
            else if (data.type == "game.started") {
                await redirectGame(data.gameId)
            }
        };


        this.socket.onclose = function(event) {
            WSConnection(document, false)
        };


        this.socket.onerror = function(error) {
            console.error("WebSocket error:", error);
        };

        document.getElementById("root").appendChild(AddModalComponent(
            "alert-close-room-modal",
            "close room.",
            "bi bi-exclamation-circle-fill",
            "Close Game",
            "Be careful. This game will be deleted if you close it.<br>Do you want to continue?",
            "btn-close-room",
            "Yes",
            "No"
        ))


        document.getElementById("root").appendChild(AddModalComponent(
            "alert-leave-room-modal",
            "leave room.",
            "bi bi-exclamation-circle-fill",
            "Leave Game",
            "Are you sure you want to leave this game?",
            "btn-leave-the-room",
            "Yes",
            "No"
        ))


        document.getElementById("root").appendChild(AddModalComponent(
            "alert-remove-player-modal",
            "remove player.",
            "bi bi-exclamation-circle-fill",
            "Remove Player",
            "Are you sure you want to remove this player from the game?",
            "btn-remove-player",
            "Yes",
            "No"
        ))
    }

    async destroy() {
        if (this.socket && this.socket.readyState === WebSocket.OPEN) {
            this.socket.close();
        }
    }
}

class PageTournament {

    constructor() {
        this.socket = null
    }

    async init () {
        const userId = getCookie(document, "userId")
        const host = window.location.host;
        const endpoint = "/api/v1/user-session/";
        await ShowTournamentRoom(localStorage.getItem("roomCode"))
        this.socket = new WebSocket(`wss://${host}${endpoint}ws/rooms/${localStorage.getItem("roomCode")}/?userId=${userId}`);

        this.socket.onopen = function(event) {
			WSConnection(document, true)
		};

		this.socket.onmessage = async (event) => {
            const data = JSON.parse(event.data);
            if (data.type == "delete_room" || (data.type == "player_list_update" && data.userRemoved == userId)) {
                resetUserIdIntoCookie(document)
                await DOMRender("/home.html")
            } else if (data.type == "player_list_update")
                await ShowTournamentRoom(localStorage.getItem("roomCode"));
            else if (data.type == "game.started") {
                await redirectGame(data.gameId)
            }
		};

        this.socket.onclose = function(event) {
			WSConnection(document, false)
		};
        this.socket.onerror = function(error) {
            console.error("WebSocket error:", error);
        };

        document.getElementById("root").appendChild(AddModalComponent(
            "alert-close-room-modal",
            "close room.",
            "bi bi-exclamation-circle-fill",
            "Close Game",
            "Be careful. This game will be deleted if you close it.<br>Do you want to continue?",
            "btn-close-room",
            "Yes",
            "No"
        ))


        document.getElementById("root").appendChild(AddModalComponent(
            "alert-leave-room-modal",
            "leave room.",
            "bi bi-exclamation-circle-fill",
            "Leave Game",
            "Are you sure you want to leave this game?",
            "btn-leave-the-room",
            "Yes",
            "No"
        ))
    }


    async destroy() {
        if (this.socket && this.socket.readyState === WebSocket.OPEN) {
            this.socket.close();
        }
    }
}

class Router {

    constructor() {
        this.page = localStorage.getItem("currentPage") ? localStorage.getItem("currentPage") : "/home.html"
        this.prevPage = "/home.html"
        this.actions = {
            "/home.html": new PageHome(),
            "/view-rooms.html": new PageViewRooms(),
            "/ranking.html": new Ranking(),
            "/watch-room.html": new PageMatchRoom(),
            "/tournament.html": new PageTournament(),
            "/game.html": new PageGame()
        }
        localStorage.setItem("currentPage", this.page)
        this.roomCode = localStorage.getItem("roomCode") ? localStorage.getItem("roomCode") : null
        this.gameId = localStorage.getItem("gameId") ? localStorage.getItem("gameId") : null
        this.isF5 = true

        document.addEventListener("click", async event => {
            await HandleEvents(event, this.roomCode)
        });

        window.onpopstate = async (event) => {
            if (event.state && event.state.page) {
                await DOMRender(event.state.page, false);
            }
        };
        this.restoreHistory();
    }

    async navigateTo(newPage, addToHistory = true) {
        if (this.actions[newPage]) {
            if (this.page !== newPage || this.isF5) {
                const currentActions = this.actions[this.page];
                if (currentActions && currentActions.destroy) {
                    await currentActions.destroy();
                }
                const newActions = this.actions[newPage];
                if (newActions && newActions.init) {
                    await newActions.init();
                }
                this.isF5 = false
            }

            this.prevPage = this.page
            this.page = newPage
            localStorage.setItem("currentPage", this.page)

            if (addToHistory) {
                const state = { page: newPage };
                window.history.pushState(state, newPage, window.location.href);
                this.saveHistory(state, newPage, window.location.href);
            }
        }
    }

    updateRoomCode(roomCode) {
        this.roomCode = roomCode
        localStorage.setItem("roomCode", this.roomCode)
        Object.values(this.actions).forEach(page => {
            page.roomCode = this.roomCode
        });
    }

    updateGameId(gameId) {
        this.gameId = gameId
        localStorage.setItem("gameId", this.gameId)
        Object.values(this.actions).forEach(page => {
            page.gameId = this.gameId
        });
    }

    saveHistory(state, title, url) {
        const savedHistory = JSON.parse(sessionStorage.getItem("history")) || [];
        savedHistory.push({ state, title: title, url: url });
        sessionStorage.setItem("history", JSON.stringify(savedHistory));
    }

    restoreHistory() {
        const savedHistory = JSON.parse(sessionStorage.getItem("history")) || [];
        if (savedHistory.length > 0) {
            const first = savedHistory.shift();
            window.history.replaceState(first.state, first.title, first.url);
            savedHistory.forEach(state => {
                window.history.pushState(state.state, state.title, state.url);
            });
        }
    }
}


