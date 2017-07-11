#include "KeyBoard.h"
USING_NS_CC;

namespace User
{
	Scene* KeyBoardInput::createScene()
	{
		auto scene = Scene::create();
		auto layer = KeyBoardInput::create();
		scene->addChild(layer);
		return scene;
	}

	bool KeyBoardInput::init()
	{
		if (!Layer::init()) { return false; }

		auto s = Sprite::create("HelloWorld.png");
		s->setPosition(Director::getInstance()->getVisibleSize() / 2);
		this->addChild(s);
		this->setSprite(s);

		auto listener = EventListenerKeyboard::create();
		listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* keyEvent) {
		
			switch (keyCode)
			{
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:

				sprite->setPositionX(sprite->getPositionX() - 1);

				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: 

				sprite->setPositionX(sprite->getPositionX() + 1);

				break;
			case EventKeyboard::KeyCode::KEY_UP_ARROW:

				sprite->setPositionY(sprite->getPositionY() + 1);

				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:

				sprite->setPositionY(sprite->getPositionY() - 1);

				break;
			default:
				break;
			}
		};
		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


		this->scheduleUpdate();
		return true;
	}

	void KeyBoardInput::update(float delta)
	{
		log("SpritePosition  x=%f y=%f", sprite->getPositionX(), sprite->getPositionY() );
	}

}
