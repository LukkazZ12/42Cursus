## Padrão de commits
A ideia aqui e descrever como podemos detalhar nossos commits de forma que qualquer pessoa que leia o commit consiga entender o que foi feito.

> [!TIP] Exemplo:
> 
> ```sh
> <tag>: <issue-hash> <title>
>     <description>
> ```
>
> ```sh
> git commit -m'feat: #35 implementação de endpoint GetGameRooms
>     test: add unit tests
>     test: add integration tests
>     docs: alteração na documentação do fluxo de pegar
>     salas de jogo'
> ```

### Tags

`feat:` Implementação de uma nova feature para o usuário.<br>
`fix:` Correção de um bug encontrado.<br>
`docs:` Alterações na documentação.<br>
`style:` (formatting, missing semi colons, etc; no production code change).<br>
`refactor:` Refatoração de código, (que não altera a funcionalidade).<br>
`test:` Adição de testes (unit tests, integration test, EtoE).<br>
`chore:` ?<br>

***
## Padrão de Branch
A ideia no padrão de branchs é seguir a mesma ideia que os commits.

> [!TIP] Exemplo:
>
> ```sh
> <tag>/<issue-hash>-<description>
> ```
>
> ```sh
> git commit -m'feat/#35-GetGameRooms'
> ```
