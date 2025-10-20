#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
};

