#pragma once
#include <cmath>

/// <summary>
/// 4x4行列
/// </summary>
struct Matrix4x4 final {
	float m[4][4];
};

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
	float x;
	float y;
	float z;
};

struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

// ベクトルの加法
Vector3 Add(const Vector3& v1, const Vector3& v2);
// ベクトルの減法
//Vector3 Subtract(Vector3& v1, Vector3 v2);
// スカラー倍
//Vector3 Multiply(const float& k, Vector3 v1);
// 内積
//float Dot(Vector3& v1, Vector3& v2);
// 長さ(ノルム)
//float Length(Vector3& v1);
// 正規化
//Vector3 Normalize(Vector3& v1);

// ベクトル変換
//Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
// 逆行列
Matrix4x4 Inverse(const Matrix4x4& m);
// 座標変換
Vector3 Transform_v3(const Vector3& vector, const Matrix4x4& matrix);

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
// 座標変換
// Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

// X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);
// Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);
// Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

// アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

// 単位行列の作成
Matrix4x4 MakeIdentity4x4();

// 透視投射行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
// 正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
// ビューポート変更行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);