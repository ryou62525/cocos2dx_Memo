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

		//画像を用意
		auto s = Sprite::create("HelloWorld.png");
		s->setPosition(Director::getInstance()->getVisibleSize() / 2);
		this->addChild(s);
		this->setSprite(s);

		//キーボード用のイベントリスナーを作成
		auto listener = EventListenerKeyboard::create();

		//キーボードを押したときの処理( 離した瞬間の時はlistener->onKeyReleased )
		listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* keyEvent) {	
			switch (keyCode)
			{
				//左キー
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:

				sprite->setPositionX(sprite->getPositionX() - 1);

				break;
				
				//右キー
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: 

				sprite->setPositionX(sprite->getPositionX() + 1);

				break;
			
				//上キー
			case EventKeyboard::KeyCode::KEY_UP_ARROW:

				sprite->setPositionY(sprite->getPositionY() + 1);

				break;

				//下キー
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:

				sprite->setPositionY(sprite->getPositionY() - 1);

				break;
			default:
				break;
			}
		};
		//キーボードのイベントリスナーの登録
		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


		this->scheduleUpdate();
		return true;
	}

	void KeyBoardInput::update(float delta)
	{
		//ログ表示
		log("SpritePosition  x=%f y=%f", sprite->getPositionX(), sprite->getPositionY() );
	}

}
