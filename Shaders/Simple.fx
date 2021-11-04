float4x4 mWVP;
float4x4 mWIT;
float3 cameraPos;

const float3 lightDir = float3(-0.5f, -0.5f, 0.0f);

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float3 col : COLOR0;
};

VS_OUTPUT Vert(float4 pos : POSITION, float3 normal : NORMAL)
{
	VS_OUTPUT Out;
	Out.pos = mul(pos, mWVP);
	float3 L = -lightDir;
	float3 N = normalize(mul(normal, (float3x3) mWIT));
	float theta = max(0, dot(N, L));
	Out.col = float4(1.0f, 1.0f, 1.0f, 1.0f) * theta;
	float3 halfVec = normalize(normalize(L) + normalize(cameraPos - Out.pos));
	Out.col.rgb += max(0, dot(normal, halfVec));
	return Out;
}

float4 Pixel(VS_OUTPUT In) : COLOR
{
	return float4(In.col, 1.0f);
}

technique Simple
{
	pass P0
	{
		VertexShader = compile vs_2_0 Vert();
		PixelShader = compile ps_2_0 Pixel();
	}
}
