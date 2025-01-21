function	createTexture(r, g, b)
{
	for (let i = 0, ind = 0; i < TEX_SIDE; i++)
	{
		let	squareX = Math.floor(i / (TEX_SIDE / TEX_ROLS));

		for (let j = 0; j < TEX_SIDE; j++)
		{
			let	squareY = Math.floor(j / (TEX_SIDE / TEX_COLS));
			let	c = (squareX % 2 != squareY % 2 ? 1 : 0);

			if (c == 1)
			{
				gTexture[ind++] = r;
				gTexture[ind++] = g;
				gTexture[ind++] = b;
			}
			else
			{
				gTexture[ind++] = 0;
				gTexture[ind++] = 0;
				gTexture[ind++] = 0;
			}
			gTexture[ind++] = 255;
		};
	};
};

function	setUpURLTexture(url, textureUnit)
{
	var	texture = gl.createTexture();
	gl.activeTexture(gl[`TEXTURE${textureUnit}`]);
	gl.bindTexture(gl.TEXTURE_2D, texture);
	gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, 1, 1, 0, gl.RGBA, gl.UNSIGNED_BYTE, new Uint8Array([255, 255, 255, 255]));

	var	img = new Image();
	img.src = url;
	img.crossOrigin = "anonymous";
	img.addEventListener('load', function()
	{
		gl.bindTexture(gl.TEXTURE_2D, texture);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, img.width, img.height, 0, gl.RGBA, gl.UNSIGNED_BYTE, img);
		gl.generateMipmap(gl.TEXTURE_2D);
	});
	return (texture);
};

function	setUpTexture(img, textureUnit)
{
	let	texture = gl.createTexture();
	gl.activeTexture(gl[`TEXTURE${textureUnit}`]);
	gl.bindTexture(gl.TEXTURE_2D, texture);

	gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, TEX_SIDE, TEX_SIDE, 0, gl.RGBA, gl.UNSIGNED_BYTE, img);
	gl.generateMipmap(gl.TEXTURE_2D);

	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);

	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);
};