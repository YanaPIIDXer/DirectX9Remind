float4x4 mWVP;

struct VS_OUTPUT
{
	float4 pos : POSITION;
};

VS_OUTPUT Vert(float4 Pos : POSITION)
{
	VS_OUTPUT Out;
	Out.pos = mul(Pos, mWVP);
	return Out;
}

float4 Pixel(VS_OUTPUT In) : COLOR
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}

technique Teapot
{
	pass P0
	{
		VertexShader = compile vs_2_0 Vert();
		PixelShader = compile ps_2_0 Pixel();
	}
}
