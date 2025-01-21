```mermaid
sequenceDiagram
    title Create Room
    Game Front End ->> User Session: POST /api/v1/user-session/create-game
    User Session ->> DB_USER_SESSION : write Game
    User Session ->> Redis game_session_queue:  envia evento de criação de jogo
    User Session ->> Game Front End: 204 No Content
    
    Game Core --) Redis game_session_queue : consume evento de criação
    Game Core --) DB_GAME_CORE : Cria o game e os usuários
    Game Core ->> Game Core : Inicia um processo async para o jogo
```

```mermaid
sequenceDiagram
    title game flow
    par send Information
        Game Front End ->> Game Core : "[wss] /api/v1/game-core/{gameId}/player-movements : send player movements"
        Game Core ->>
        Game Core ->> Redis game_action_queue_{gameId} : Send Event
    and receive information
        Game Core ->> Game Front End : "[wss] : receive map updates"
    end 

```