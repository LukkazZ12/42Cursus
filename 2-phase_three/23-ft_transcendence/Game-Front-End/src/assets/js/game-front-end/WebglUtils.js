function	makeProgram(gl, vertexShaderSrc, fragmentShaderSrc)
{
	var	vertexShader = compile(gl, gl.VERTEX_SHADER, vertexShaderSrc);
	var	fragmentShader = compile(gl, gl.FRAGMENT_SHADER, fragmentShaderSrc);
	var	program = link(gl, vertexShader, fragmentShader);

	if (program)
		return (program);
	alert("ERROR.");
};

function	compile(gl, type, source)
{
	var	shader = gl.createShader(type);

	gl.shaderSource(shader, source);
	gl.compileShader(shader);

	var	isWorking = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
	if (isWorking)
		return (shader);
	gl.deleteShader(shader);
};

function	link(gl, vertexShader, fragmentShader)
{
	var	program = gl.createProgram();

	gl.attachShader(program, vertexShader);
	gl.attachShader(program, fragmentShader);
	gl.linkProgram(program);

	var	isWorking = gl.getProgramParameter(program, gl.LINK_STATUS);
	if (isWorking)
		return (program);

	gl.deleteProgram(program);
};

function	rondomizeRGBAColor(a = 1)
{
	let	r = Math.random();
	let	g = Math.random();
	let	b = Math.random();

	if (a == 0)
		return ([r, g, b]);
	if (a == -1)
		a = Math.random();

	return ([r, g, b, a]);
}

function	randomizeInt(min, max)
{
	return	(Math.floor(Math.random() * (max - min)) + min);
}