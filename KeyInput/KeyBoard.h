#pragma once
#include <cocos2d.h>

namespace User
{
	class KeyBoardInput : cocos2d::Layer
	{
	public:

		static cocos2d::Scene* createScene();
		bool init();
		CREATE_FUNC(KeyBoardInput);

		CC_SYNTHESIZE(cocos2d::Sprite*, sprite, Sprite);

		void update(float delta);

	};

}

