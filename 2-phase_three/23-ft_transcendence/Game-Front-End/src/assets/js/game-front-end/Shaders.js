function	createShaders()
{
	gShader.program = makeProgram(gl, gVertexShaderSrc, gFragmentShaderSrc);
	gl.useProgram(gShader.program);

	createBuffers();

	gShader.uModel = gl.getUniformLocation(gShader.program, "uModel");
	gShader.uView = gl.getUniformLocation(gShader.program, "uView");
	gShader.uPerspective = gl.getUniformLocation(gShader.program, "uPerspective");
	gShader.uInverseTranspose = gl.getUniformLocation(gShader.program, "uInverseTranspose");

	gCtx.perspective = perspective(FOVY, ASPECT, NEAR, FAR);
	gl.uniformMatrix4fv(gShader.uPerspective, false, flatten(gCtx.perspective));

	gCtx.view = lookAt(gCamera.pos, gCamera.at, gCamera.up);
	gl.uniformMatrix4fv(gShader.uView, false, flatten(gCtx.view));

	gShader.uLightPos = gl.getUniformLocation(gShader.program, "uLightPos");
	gl.uniform4fv(gShader.uLightPos, LIGHT.pos);

	gShader.uAmbColor = gl.getUniformLocation(gShader.program, "uAmbColor");
	gShader.uDifColor = gl.getUniformLocation(gShader.program, "uDifColor");
	gShader.uSpecColor = gl.getUniformLocation(gShader.program, "uSpecColor");
	gShader.uAlphaSpec = gl.getUniformLocation(gShader.program, "uAlphaSpec");

	gl.uniform1f(gShader.uAlphaSpec, gCtx.alfaEspecular);
	gl.uniform4fv(gShader.uAmbColor, mult(LIGHT.amb, MAT.amb));
	gl.uniform4fv(gShader.uDifColor, mult(LIGHT.dif, MAT.dif));
	gl.uniform4fv(gShader.uSpecColor, LIGHT.spec);
	gl.uniform1f(gShader.uAlphaSpec, MAT.alfa);

	gShader.uTextureMap = gl.getUniformLocation(gShader.program, "uTextureMap");

	setUpTexture(gTexture, URLS.length);
	for (let i = 0; i < URLS.length; i++)
		setUpURLTexture(URLS[i], i);
};

function	createBuffers(obj)
{
	let	bufPositions = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, bufPositions);
	gl.bufferData(gl.ARRAY_BUFFER, flatten(gPositions), gl.STATIC_DRAW);

	var	aPosition = gl.getAttribLocation(gShader.program, "aPosition");
	gl.vertexAttribPointer(aPosition, 4, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(aPosition);

	let	bufColors = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, bufColors);
	gl.bufferData(gl.ARRAY_BUFFER, flatten(gColors), gl.STATIC_DRAW);

	var	aColor = gl.getAttribLocation(gShader.program, "aColor");
	gl.vertexAttribPointer(aColor, 4, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(aColor);

	let	bufNormals = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, bufNormals);
	gl.bufferData(gl.ARRAY_BUFFER, flatten(gNormals), gl.STATIC_DRAW);

	var	aNormal = gl.getAttribLocation(gShader.program, "aNormal");
	gl.vertexAttribPointer(aNormal, 3, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(aNormal);

	let	bufTextures = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, bufTextures);
	gl.bufferData(gl.ARRAY_BUFFER, flatten(gTextures), gl.STATIC_DRAW);

	var aTextCoord = gl.getAttribLocation(gShader.program, "aTextCoord");
	gl.vertexAttribPointer(aTextCoord, 2, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(aTextCoord);
};