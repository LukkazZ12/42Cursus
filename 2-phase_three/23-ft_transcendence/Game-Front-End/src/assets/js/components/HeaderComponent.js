function WSConnection(document, isConnected) {
    let element = document.getElementById("connected-ws")
    if (element) {
        element.innerHTML = isConnected === true ?
            `<h5 class="bi bi-c-circle-fill text-success"><span style="font-size: 20px"> connected</span></h2>`
            : `<h5 class="bi bi-c-circle-fill text-danger"><span style="font-size: 20px"> disconnected</span></h2>`
    }
}
