#include "Object3d.hlsli"
//float4 main() : SV_TARGET
//{
//	return float4(1.0f, 1.0f, 1.0f, 1.0f);
//}



struct Material {
	float32_t4 color;
	int32_t enableLighting;
};
struct DirectionalLight {
	float32_t4 color; // ライトの色
	float32_t3 direction; // ライトの向き
	float intensity; // 輝度
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);


struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	output.color = gMaterial.color;
	float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);
	if (gMaterial.enableLighting != 0) {
		float cos = saturate(dot(normalize(input.normal), -gDirectionalLight.direction));
		output.color = gMaterial.color * textureColor * gDirectionalLight.color* cos* gDirectionalLight.intensity;
	}
	else {
		output.color = gMaterial.color * textureColor;
	}
	return output;
}

