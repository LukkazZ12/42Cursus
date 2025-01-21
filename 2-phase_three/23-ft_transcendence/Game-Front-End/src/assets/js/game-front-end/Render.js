function	drawOnCanvas(data)
{
	setup(data);
	render();
};

function	setup(data)
{
	const	parsedData = JSON.parse(data);
	const	{ players, ball, numberOfPlayers, fieldAttributes, gameStatus, lastPlayerHit } = parsedData;

	gPong.gameStatus = gameStatus;
	gPong.players = players;
	gPong.ball = ball;
	gPong.numberOfPlayers = numberOfPlayers;
	gPong.numberOfObjects = gPong.numberOfPlayers + 2;
	gPong.fieldAttributes = fieldAttributes;
	gPong.fieldHeight = fieldAttributes["height"];
	gPong.fieldWidth = fieldAttributes["height"];
	gPong.lastPlayerHit = lastPlayerHit;
	if (gPong.lastPlayerHit || gPong.gameStatus == "WAITING")
		gPong.changeBallColor = TRUE;
	if (gPong.gameStatus == "PLAYING")
		gPong.doOnceChangeColor = TRUE;
	if (gPong.numberOfPlayers == 2)
		gPong.fieldWidth = fieldAttributes["width"];
	setObjectsColors();
	if (doOnce)
	{
		createTexture(255, 255, 255);
		createObjects();
		initObjects();
		insertAttributes();
		gl.viewport(0, 0, gCanvas.width, gCanvas.height);
		gl.clearColor(BACKGROUND[0], BACKGROUND[1], BACKGROUND[2], BACKGROUND[3]);
		gl.enable(gl.DEPTH_TEST);
		createShaders();
		doOnce = false;
	}
};

function	render()
{
	let	time = Date.now();

	gPong.delta = (time - gPong.time) / 1000;
	if (gPong.step)
		gPong.delta = 0.3;
	if (!gPong.running && !gPong.step)
		gPong.delta = 0;
	gPong.time = time;
	gPong.step = false;
	updateObjectsPosition();
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

	let	begin = 0;

	for (let i = 0; i < gPong.numberOfObjects; i++)
	{
		calculateMatrices(gObjects[i]);
		gl.drawArrays(gl.TRIANGLES, begin, gObjects[i].numberOfPositions);
		begin += gObjects[i].numberOfPositions;
	}
};