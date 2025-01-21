function	Cube()
{
	this.draw = true;
	this.numberOfPositions = 0;
	this.positions = [];
	this.normals = [];
	this.colors = [];
	this.textures = [];
	this.text = 0;
	this.pos = vec3(0, 0, 0);
	this.pos2 = vec3(0, 0, 0);
	this.vTrans = vec3(0, 0, 0);
	this.trans = this.pos;
	this.theta = vec3(0, 0, 0);
	this.vTheta = vec3(0, 0, 0);
	this.rot = this.theta;
	this.scale = vec3(1, 1, 1);
	this.v = vec3(0, 0, 0);
	this.model = mat4();
	this.init = function(cube)
	{
		square(this.positions, this.normals, CUBE_VERTICES, 1, 0, 3, 2);
		square(this.positions, this.normals, CUBE_VERTICES, 2, 3, 7, 6);
		square(this.positions, this.normals, CUBE_VERTICES, 3, 0, 4, 7);
		square(this.positions, this.normals, CUBE_VERTICES, 6, 5, 1, 2);
		square(this.positions, this.normals, CUBE_VERTICES, 4, 5, 6, 7);
		square(this.positions, this.normals, CUBE_VERTICES, 5, 4, 0, 1);
		this.numberOfPositions = this.positions.length;
		this.model = mult(scale(this.scale[0], this.scale[1], this.scale[2]), this.model);
		this.model = mult(rotate(this.theta[AXIS_Z_IND], AXIS_Z), this.model);
		this.model = mult(rotate(this.theta[AXIS_Y_IND], AXIS_Y), this.model);
		this.model = mult(rotate(this.theta[AXIS_X_IND], AXIS_X), this.model);
		this.model = mult(translate(this.pos[0], this.pos[1], this.pos[2]), this.model);
	};
	this.updateModel = function(cube)
	{
		this.model = mat4();
		this.model = mult(scale(this.scale[0], this.scale[1], this.scale[2]), this.model);
		this.model = mult(rotate(this.rot[AXIS_Z_IND], AXIS_Z), this.model);
		this.model = mult(rotate(this.rot[AXIS_Y_IND], AXIS_Y), this.model);
		this.model = mult(rotate(this.rot[AXIS_X_IND], AXIS_X), this.model);
		this.trans = add(this.trans, mult(gPong.delta, this.vTrans));
		this.pos2 = add(this.pos, this.trans);
		this.model = mult(translate(this.pos2[0], this.pos2[1], this.pos2[2]), this.model);
	};
};

function	square(positions, normals, vertices, a, b, c, d)
{
	var	t1 = subtract(vertices[b], vertices[a]);
	var	t2 = subtract(vertices[c], vertices[b]);
	var	normal = cross(t1, t2);
	normal = vec3(normal);

	positions.push(vertices[a]);
	normals.push(normal);
	positions.push(vertices[b]);
	normals.push(normal);
	positions.push(vertices[c]);
	normals.push(normal);
	positions.push(vertices[a]);
	normals.push(normal);
	positions.push(vertices[c]);
	normals.push(normal);
	positions.push(vertices[d]);
	normals.push(normal);
};

function	Sphere(numberOfDivisions = 4)
{
	this.draw = true;
	this.numberOfPositions = 0;
	this.positions = [];
	this.normals = [];
	this.colors = [];
	this.textures = [];
	this.text = 0;
	this.pos = vec3(0, 0, 0);
	this.pos2 = vec3(0, 0, 0);
	this.vTrans = vec3(1, 1, 0);
	this.bounciness = 1;
	this.trans = this.pos;
	this.theta = vec3(0, 0, 0);
	this.vTheta = vec3(0, 0, 0);
	this.vTheta1 = vec3(0, 0, 0);
	this.rot = this.theta;
	this.rot1 = this.theta;
	this.scale = vec3(1, 1, 1);
	this.v = vec3(0, 0, 0);
	this.model = mat4();
	this.init = function()
	{
		this.pos2 = this.pos;
		for (let i = 0; i < SP_TRIANGLES.length; i++)
		{
			let	a, b, c;
			[a, b, c] = SP_TRIANGLES[i];
			splitTriangles(a, b, c, numberOfDivisions, this.positions, this.normals);
		}
		this.numberOfPositions = this.positions.length;
		this.model = mult(scale(this.scale[0], this.scale[1], this.scale[2]), this.model);
		this.model = mult(rotate(this.theta[AXIS_Z_IND], AXIS_Z), this.model);
		this.model = mult(rotate(this.theta[AXIS_Y_IND], AXIS_Y), this.model);
		this.model = mult(rotate(this.theta[AXIS_X_IND], AXIS_X), this.model);
		this.model = mult(translate(this.pos[0], this.pos[1], this.pos[2]), this.model);
	};
	this.updateModel = function(sphere)
	{
		
		this.model = mat4();
		this.model = mult(scale(this.scale[0], this.scale[1], this.scale[2]), this.model);
		if (gPong.gameStatus == "PLAYING")
		{
			this.rot = add(this.rot, this.vTheta);
			this.model = mult(rotate(this.rot[AXIS_Z_IND], AXIS_Z), this.model);
			this.model = mult(rotate(this.rot[AXIS_Y_IND], AXIS_Y), this.model);
			this.model = mult(rotate(this.rot[AXIS_X_IND], AXIS_X), this.model);
		}
		this.trans = add(this.pos, mult(gPong.delta, this.vTrans));
		this.pos = this.trans;
		this.model = mult(translate(this.trans[0], this.trans[1], this.trans[2]), this.model);
	};
};

function	splitTriangles(a, b, c, numberOfDivisions, positions, normals)
{
	if (numberOfDivisions > 0)
	{
		let	ab = mix(a, b, 0.5);
		let	bc = mix(b, c, 0.5);
		let	ca = mix(c, a, 0.5);

		ab = normalize(ab, true);
		bc = normalize(bc, true);
		ca = normalize(ca, true);

		splitTriangles(a, ab, ca, numberOfDivisions - 1, positions, normals);
		splitTriangles(b, bc, ab, numberOfDivisions - 1, positions, normals);
		splitTriangles(c, ca, bc, numberOfDivisions - 1, positions, normals);
		splitTriangles(ab, bc, ca, numberOfDivisions - 1, positions, normals);
	}
	else
	{
		var	t1 = subtract(b, a);
		var	t2 = subtract(c, a);
		var	normal = cross(t1, t2);
		normal = vec3(normal);

		positions.push(a);
		normals.push(normal);
		positions.push(b);
		normals.push(normal);
		positions.push(c);
		normals.push(normal);
	}
};

function	Camera()
{
	this.pos = EYE;
	this.at = AT;
	this.dir = DIR;
	this.dir4 = vec4(0, 0, 0, 0);
	this.up = UP;
	this.theta = vec3(0, 0, 0);
	this.vTrans = 0;
	this.trans = vec3(0, 0, 0);
};