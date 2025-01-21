async function GetRankingAsync(filters, document) {
    return await fetch(`/api/v1/game-core/games/ranking/?currentPage=${filters.currentPage}&pageSize=${filters.pageSize}&filterLabel=${filters.filterLabel}`, {
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

const RankingRepository = {
    GetRankingAsync
}