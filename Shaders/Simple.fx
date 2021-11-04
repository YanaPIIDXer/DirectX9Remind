float4x4 mWVP;

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float3 col : COLOR0;
};

VS_OUTPUT Vert(float4 pos : POSITION, float3 normal : NORMAL)
{
	VS_OUTPUT Out;
	Out.pos = mul(pos, mWVP);
	Out.col = normal;
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
