async function ShowRanking(filters, document) {
    const response = await RankingRepository.GetRankingAsync(filters, document);
    if (response.status === true) {
        const data = response.data;
        let paginatedGroup = document.getElementById("paginated-ranking");
        PaginationComponent(paginatedGroup, data["paginatedItems"], "listRanking");

        let ranking = data["paginatedItems"]["Data"];
        const listGroup = document.getElementById('rooms-list');
        listGroup.innerHTML = ""
        ranking.forEach(e => {
            const listItem = document.createElement('div')
            i = ranking.indexOf(e) + 1;
            let position = "<i class='m-0 h3 bi bi-dash-circle-fill text-warning'></i>"
            if (i < 10)
                position = `<i class="m-0 h3 bi bi-${i}-circle-fill text-success"></i>`
            listItem.innerHTML = `
            <div class="container mt-3">
                <div class="row border rounded p-2 shadow-sm">
                    <div class="col-3 text-dark d-flex flex-row justify-content-start align-items-center">
                        ${position}
                        <div class="d-flex flex-column ps-2">
                            <p class="m-0"><small>player:</small></p>
                            <p class="m-0"><strong class="font-weight-bold">${e.name}</strong></p>
                        </div>
                    </div>
                    <div class="col-3 text-center">
                        <i class="m-0 bi bi-crosshair"></i>
                        <p class="m-0"><small>Total Points</small></p> 
                        <p class="m-0"><strong class="text-success">${e.total_points}</strong></p>
                    </div>
                    <div class="col-2 text-center">
                        <i class="m-0 bi bi-trophy-fill"></i>
                        <p class="m-0"><small>Wins</small></p>
                        <p class="m-0"><strong class="text-success">${e.total_wins}</strong></p>
                    </div>
                    <div class="col-2 text-center">
                        <i class="m-0 bi bi-shield-fill-x"></i>
                        <p class="m-0"><small>Losses</small></p>
                        <p class="m-0"><strong class="text-danger">${e.total_losses}</strong></p>
                    </div>
                    <div class="col-2 text-center">
                        <i class="m-0 bi bi-input-cursor"></i>
                        <p class="m-0"><small>Draws</small></p>
                        <p class="m-0"><strong class="text-danger">${e.total_draws}</strong></p>
                    </div>
                </div>
            </div>
            `
            listGroup.appendChild(listItem);
        });
    }
}