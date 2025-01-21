function	createObjects()
{
	for (let i = 0; i < 3; i++)
		gObjects.push(new Cube());
	gObjects.push(new Sphere());
	if (gPong.numberOfPlayers == 4)
	{
		for (let i = 0; i < 2; i++)
			gObjects.push(new Cube());
	}
};

function	initObjects(players)
{
	initField();
	initGoalkeepers();
	initBall();
};

function	initField()
{
	gObjects[FIELD].pos = vec3(0, 0, -100);
	gObjects[FIELD].scale = vec3(gPong.fieldWidth, gPong.fieldHeight, 4);
	gObjects[FIELD].text = 0;
	gObjects[FIELD].init();
	for (let j = 0; j < gObjects[FIELD].numberOfPositions; j++)
		gObjects[FIELD].colors.push(vec4(1, 1, 1, 1));
	for (let j = 0; j < 6; j++)
	{
		gObjects[FIELD].textures.push(vTextura[0]);
		gObjects[FIELD].textures.push(vTextura[1]);
		gObjects[FIELD].textures.push(vTextura[2]);
		gObjects[FIELD].textures.push(vTextura[0]);
		gObjects[FIELD].textures.push(vTextura[2]);
		gObjects[FIELD].textures.push(vTextura[3]);
	}
};

function	initGoalkeepers()
{
	gObjects[GOALKEEPER_0].pos = vec3(gPong.players["0"].x, gPong.players["0"].y, -94);
	gObjects[GOALKEEPER_0].scale = vec3(gPong.players["0"].width, gPong.players["0"].height, 8);
	gObjects[GOALKEEPER_0].init();
	for (let j = 0; j < gObjects[GOALKEEPER_0].numberOfPositions; j++)
	{
		gObjects[GOALKEEPER_0].colors.push(gPong.goalkeeper1Color);
		gObjects[GOALKEEPER_0].textures.push(NO_TEXTURE);
	}
	gObjects[GOALKEEPER_1].pos = vec3(gPong.players["1"].x, gPong.players["1"].y, -94);
	gObjects[GOALKEEPER_1].scale = vec3(gPong.players["1"].width, gPong.players["1"].height, 8);
	gObjects[GOALKEEPER_1].init();
	for (let j = 0; j < gObjects[GOALKEEPER_1].numberOfPositions; j++)
	{
		gObjects[GOALKEEPER_1].colors.push(gPong.goalkeeper2Color);
		gObjects[GOALKEEPER_1].textures.push(NO_TEXTURE);
	}
	if (gPong.numberOfPlayers == 4)
	{
		gObjects[GOALKEEPER_2].pos = vec3(gPong.players["2"].x, gPong.players["2"].y, -94);
		gObjects[GOALKEEPER_2].scale = vec3(gPong.players["2"].width, gPong.players["2"].height, 8);
		gObjects[GOALKEEPER_2].init();
		for (let j = 0; j < gObjects[GOALKEEPER_2].numberOfPositions; j++)
		{
			gObjects[GOALKEEPER_2].colors.push(gPong.goalkeeper3Color);
			gObjects[GOALKEEPER_2].textures.push(NO_TEXTURE);
		}
		gObjects[GOALKEEPER_3].pos = vec3(gPong.players["3"].x, gPong.players["3"].y, -94);
		gObjects[GOALKEEPER_3].scale = vec3(gPong.players["3"].width, gPong.players["3"].height, 8);
		gObjects[GOALKEEPER_3].init();
		for (let j = 0; j < gObjects[GOALKEEPER_3].numberOfPositions; j++)
		{
			gObjects[GOALKEEPER_3].colors.push(gPong.goalkeeper4Color);
			gObjects[GOALKEEPER_3].textures.push(NO_TEXTURE);
		}
	}
};

function	initBall()
{
	gObjects[BALL].pos = vec3(0, 0, -96);
	gObjects[BALL].scale = vec3(gPong.ball.radius, gPong.ball.radius, gPong.ball.radius);
	gObjects[BALL].vTrans = vec3(randomizeInt(10, 20), randomizeInt(10, 20), 0);
	gObjects[BALL].vTheta = vec3(0, 0, 1);
	gObjects[BALL].text = 1;
	gObjects[BALL].init();
	for (let j = 0; j < gObjects[BALL].numberOfPositions; j++)
	{
		gObjects[BALL].colors.push(vec4(1, 1, 1, 0));

		let	x = Math.atan2(Math.abs(gObjects[BALL].positions[j][0]),
			gObjects[BALL].positions[j][2]) / (2 * Math.PI);

		if (j >= gObjects[BALL].numberOfPositions / 2)
			x = 1 - x;
		gObjects[BALL].textures.push(vec2(x,
			Math.acos(gObjects[BALL].positions[j][1]) / Math.PI));
	}
};

function	insertAttributes()
{
	for (let i = 0; i < gPong.numberOfObjects; i++)
	{
		for (let j = 0; j < gObjects[i].numberOfPositions; j++)
		{
			gPositions.push(gObjects[i].positions[j]);
			gColors.push(gObjects[i].colors[j]);
			gNormals.push(gObjects[i].normals[j]);
			gTextures.push(gObjects[i].textures[j]);
		}
	}
};

function	setObjectsColors()
{
	let	colorVec = PlayerColor[gPong.players["0"]["color"]];

	gPong.goalkeeper1Color = vec4(colorVec[0] / 255, colorVec[1] / 255, colorVec[2] / 255, 1);
	colorVec = PlayerColor[gPong.players["1"]["color"]];
	gPong.goalkeeper2Color = vec4(colorVec[0] / 255, colorVec[1] / 255, colorVec[2] / 255, 1);
	if (gPong.numberOfPlayers == 4)
	{
		colorVec = PlayerColor[gPong.players["2"]["color"]];
		gPong.goalkeeper3Color = vec4(colorVec[0] / 255, colorVec[1] / 255, colorVec[2] / 255, 1);
		colorVec = PlayerColor[gPong.players["3"]["color"]];
		gPong.goalkeeper4Color = vec4(colorVec[0] / 255, colorVec[1] / 255, colorVec[2] / 255, 1);
	}
};

function	updateObjectsPosition()
{
	if (gPong.changeBallColor == TRUE)
	{
		if (gPong.lastPlayerHit)
		{
			let	colorVec = PlayerColor[gPong.lastPlayerHit["color"]];
			createTexture(colorVec[0], colorVec[1], colorVec[2]);
			setUpTexture(gTexture, URLS.length);
		}
		else if (gPong.gameStatus == "WAITING" && gPong.doOnceChangeColor)
		{
			createTexture(255, 255, 255);
			setUpTexture(gTexture, URLS.length);
			gPong.doOnceChangeColor = FALSE;
		}
		gPong.changeBallCollor = FALSE;
	}
	gObjects[GOALKEEPER_0].pos[1] = gPong.players["0"].y;
	gObjects[GOALKEEPER_1].pos[1] = gPong.players["1"].y;
	gObjects[BALL].pos[0] = gPong.ball.x;
	gObjects[BALL].pos[1] = gPong.ball.y;
	if (gPong.numberOfPlayers == 4)
	{
		gObjects[GOALKEEPER_2].pos[0] = gPong.players["2"].x;
		gObjects[GOALKEEPER_3].pos[0] = gPong.players["3"].x;
	}
	for(let i = 0; i < gPong.numberOfObjects; i++)
		gObjects[i].updateModel();
};

function	calculateMatrices(obj)
{
	let modelView = mult(gCtx.view, obj.model);
	let	modelViewInv = inverse(modelView);
	let	modelViewInvTrans = transpose(modelViewInv);

	gl.uniformMatrix4fv(gShader.uModel, false, flatten(obj.model));
	gl.uniformMatrix4fv(gShader.uInverseTranspose, false, flatten(modelViewInvTrans));
	gl.uniform1i(gShader.uTextureMap, obj.text);
};