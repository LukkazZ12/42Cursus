class CustomError extends Error {
    constructor(title, message) {
        super(message);
        this.name = "CustomError";
        this.title = title;
    }
}

