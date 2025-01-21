const	TRUE = 1;
const	FALSE = 0;

const	BALL_POSITION = vec3(0, 0, -96);
const	BALL_SCALE = vec3(2, 2, 2);
const	GOALKEEPER_1_POSITION = vec3(-44, 0, -94);
const	GOALKEEPER_2_POSITION = vec3(44, 0, -94);
const	GOALKEEPER_SCALE = vec3(2, 16, 8);
const	FIELD_POSITION = vec3(0, 0, -100);

const	CUBE_VERTICES = [
	vec4(-0.5, -0.5, 0.5, 1.0),
	vec4(-0.5, 0.5, 0.5, 1.0),
	vec4(0.5, 0.5, 0.5, 1.0),
	vec4(0.5, -0.5, 0.5, 1.0),
	vec4(-0.5, -0.5, -0.5, 1.0),
	vec4(-0.5, 0.5, -0.5, 1.0),
	vec4(0.5, 0.5, -0.5, 1.0),
	vec4(0.5, -0.5, -0.5, 1.0)
];

const	SP_POS_VERT = [
	vec4(1.0, 0.0, 0.0, 1),
	vec4(0.0, 1.0, 0.0, 1),
	vec4(0.0, 0.0, 1.0, 1),
];

const	SP_NEG_VERT = [
	vec4(-1.0, 0.0, 0.0, 1),
	vec4(0.0, -1.0, 0.0, 1),
	vec4(0.0, 0.0, -1.0, 1),
];

const	SP_TRIANGLES = [
	[SP_POS_VERT[0], SP_POS_VERT[1], SP_POS_VERT[2]],
	[SP_POS_VERT[0], SP_NEG_VERT[2], SP_POS_VERT[1]],

	[SP_POS_VERT[0], SP_POS_VERT[2], SP_NEG_VERT[1]],
	[SP_POS_VERT[0], SP_NEG_VERT[1], SP_NEG_VERT[2]],

	[SP_NEG_VERT[0], SP_POS_VERT[2], SP_POS_VERT[1]],
	[SP_NEG_VERT[0], SP_POS_VERT[1], SP_NEG_VERT[2]],

	[SP_NEG_VERT[0], SP_NEG_VERT[1], SP_POS_VERT[2]],
	[SP_NEG_VERT[0], SP_NEG_VERT[2], SP_NEG_VERT[1]],
];

const	FIELD = 0;
const	GOALKEEPER_0 = 1;
const	GOALKEEPER_1 = 2;
const	BALL = 3;
const	GOALKEEPER_2 = 4;
const	GOALKEEPER_3 = 5;

const	LIGHT = {
	pos: vec4(0.0, 40.0, 0.0, 1.0),
	amb: vec4(0.2, 0.2, 0.2, 1.0),
	dif: vec4(1.0, 1.0, 1.0, 1.0),
	spec: vec4(1.0, 1.0, 1.0, 1.0),
};

const	MAT = {
	amb: vec4(0.4, 0.4, 0.4, 1.0),
	dif: vec4(1.0, 1.0, 1.0, 1.0),
	alfa: 50.0,
};

const	FOVY = 60;
const	ASPECT = 1;
const	NEAR = 0.1 / 500 * 500;
const	FAR = 5000 / 500 * 500;
const	EYE = vec3(0, 0, 0);
const	AT = vec3(0, 0, -1);
const	DIR = vec3(0, 0, -1);
const	UP = vec3(0, 1, 0);
const	CAMERA_VTRANS = 150 / 500 * 500;
const	CAMERA_THETA = Math.PI / 2;
const	CAMERA_THETA_DEGREES = CAMERA_THETA * 180 / Math.PI;

const	BACKGROUND = [0.0, 0.0, 1.0, 0.2];
const	AXIS_X_IND = 0;
const	AXIS_Y_IND = 1;
const	AXIS_Z_IND = 2;
const	AXIS_X = vec3(1, 0, 0);
const	AXIS_Y = vec3(0, 1, 0);
const	AXIS_Z = vec3(0, 0, 1);

const	TEX_ROLS = 8;
const	TEX_COLS = 8;
const	TEX_SIDE = 128;
const	TEX_COLOR_SIZE = 4;

const	vTextura = [
	vec2(0.0, 0.0),
	vec2(0.0, 1.0),
	vec2(1.0, 1.0),
	vec2(1.0, 0.0)
];
const	NO_TEXTURE = vec2(-1, -1);

const	URL_FIELD = "./assets/img/milkyWayField.png"
const	URLS = [URL_FIELD];

const	gTexture = new Uint8Array(TEX_COLOR_SIZE * TEX_SIDE * TEX_SIDE);

var		gPong = {};
var		gInterface = {};
var		gCanvas;
var		gl;
var		gObjects = [];
var		gCamera;
var		gShader = {};
var		gCtx = {};
var		gPositions = [];
var		gColors = [];
var		gNormals = [];
var		gTextures = [];
var		doOnce;

var		gVertexShaderSrc = `#version 300 es

in vec4			aPosition;
in vec4			aColor;
in vec3			aNormal;
in vec2			aTextCoord;

uniform mat4	uModel;
uniform mat4	uView;
uniform mat4	uPerspective;
uniform mat4	uInverseTranspose;
uniform vec4	uLightPos;

out vec3		vNormal;
out vec3		vLight;
out vec3		vView;
out vec4		vColor;
out vec2		vTextCoord;

void	main()
{
	mat4	modelView = uView * uModel;
	gl_Position = uPerspective * modelView * aPosition;

	vNormal = mat3(uInverseTranspose) * aNormal;
	vec4	pos = modelView * aPosition;

	vLight = (uView * uLightPos - pos).xyz;
	vView = -(pos.xyz);
	vColor = aColor;
	vTextCoord = aTextCoord;
}`;

var		gFragmentShaderSrc = `#version 300 es

precision highp float;

in vec3				vNormal;
in vec3				vLight;
in vec3				vView;
in vec4				vColor;
in vec2				vTextCoord;

uniform vec4		uAmbColor;
uniform vec4		uDifColor;
uniform vec4		uSpecColor;
uniform float		uAlphaSpec;
uniform sampler2D	uTextureMap;

out vec4			finalColor;

void main()
{
	vec3	normalV = normalize(vNormal);
	vec3	lightV = normalize(vLight);
	vec3	viewV = normalize(vView);
	vec3	halfV = normalize(lightV + viewV);
	vec4	vColorAux = vColor;

	if (vTextCoord.x != -1.0)
		vColorAux *= texture(uTextureMap, vTextCoord);
	float	kd = max(0.0, dot(normalV, lightV));
	vec4	difuse = kd * uDifColor * vColorAux;

	float	ks = pow(max(0.0, dot(normalV, halfV)), uAlphaSpec);
	vec4	specular = vec4(0, 0, 0, 1);

	if (kd > 0.0)
		specular = ks * uSpecColor;
	finalColor = difuse + specular + uAmbColor * vColorAux;
	finalColor.a = 1.0;
}`;