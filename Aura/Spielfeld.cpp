#include "spielfeld.h"
#include "Spieler.h"
#include "Aura.h"
#include "Gegner.h"
#include <iostream>
#include "ParticleEmitter.h"
#include "Terrain.h"

#include "Drone.h"
#include "rammy.h"

#include "GUI/windows/HealthBar.h"
#include "GUI/windows/xpBar.h"


Spielfeld::Spielfeld(sf::RenderWindow *window)
{
	width=50;
	height=60;
	rWindow = window;

	//Objects
	player = createObject<Spieler>(30, 30);
	createObject<Rammy>(300.f, 350.f);
	createObject<Rammy>(500, 350.f);
	createObject<Rammy>(700, 400);
	createObject<Rammy>(300.f, 200);

	createObject<Rammy>(300.f, 350.f);
	createObject<Rammy>(500, 350.f);
	createObject<Rammy>(700, 400);
	createObject<Rammy>(300.f, 200);
	createObject<Rammy>(300.f, 350.f);
	createObject<Rammy>(500, 350.f);
	createObject<Rammy>(700, 400);
	createObject<Rammy>(300.f, 200);


	//createObject<Drone>(500, 350.f);
	//createObject<Drone>(700, 400);
	//createObject<Drone>(300.f, 200);


	//createObject<ParticleEmitter>(250.f,250.f);

	//Terrain
	Terrain * t1 = createObject<Terrain>(150.f, 100.f);
	std::vector<sf::Vector2f> vec;
	vec.push_back(sf::Vector2f(-20, 20));
	vec.push_back(sf::Vector2f(40, 60));
	vec.push_back(sf::Vector2f(40, -20));
	vec.push_back(sf::Vector2f(-20, -20));
	vec.push_back(sf::Vector2f(-100, 0));
	
	static_cast<ChainBody*>(t1->getBody())->setPoints(vec);
	t1->updateVertexArray();

	//Grenzen. Dont fucking touch. pain in the ass
	EdgeBody * p1_p2 = new EdgeBody();
	EdgeBody * p2_p3 = new EdgeBody();
	EdgeBody * p3_p4 = new EdgeBody();
	EdgeBody * p4_p1 = new EdgeBody();

	p1_p2->setMass(1);
	p2_p3->setMass(1);
	p3_p4->setMass(1);
	p4_p1->setMass(1);

	p1_p2->setPos(0, 0);
	p1_p2->setP2(sf::Vector2f(window->getSize().x, 0));

	p2_p3->setPos(p1_p2->getPos() + p1_p2->getP2());
	p2_p3->setP2(sf::Vector2f(0, window->getSize().y));

	p3_p4->setPos(p2_p3->getPos() + p2_p3->getP2());
	p3_p4->setP2(sf::Vector2f(-p1_p2->getP2().x, 0));

	p4_p1->setPos(p3_p4->getPos() + p3_p4->getP2());
	p4_p1->setP2(sf::Vector2f(0, -p2_p3->getP2().y));

	p1_p2->updateAABB();
	p2_p3->updateAABB();
	p3_p4->updateAABB();
	p4_p1->updateAABB();
	
	pSystem.addBody(p1_p2);
	pSystem.addBody(p2_p3);
	pSystem.addBody(p3_p4);
	pSystem.addBody(p4_p1);


	//Background
	backgound.create(1000, 800);
	backgound.clear(sf::Color(25, 25, 25));

	//Gui
	HealthBar * hpBar = new HealthBar;
	hpBar->setPlayer(player);
	guiSystem.addWindow(hpBar);
	XpBar * xpBar = new XpBar;
	xpBar->setPlayer(player);
	guiSystem.addWindow(xpBar);

}

void Spielfeld::tick()
{

	for(unsigned int i=0; i < objects.size(); i++)
	{
		if(objects[i]->flag_destroy == true)
		{
			delete objects[i];
			objects.erase(objects.begin()+i);
		}
	}

	for(unsigned int i=0; i < objects.size(); i++)
	{
		objects[i]->tick();
	}
	pSystem.tick();
	guiSystem.tick();
	//std::cout << objects.size();
}

void Spielfeld::render()
{
	sf::Sprite bg;
	bg.setTexture(backgound.getTexture());
	bg.setPosition(0, 0);
	rWindow->draw(bg);
	for(unsigned int i=0; i < objects.size(); i++)
	{
		if(objects[i]->flag_visible)
		{
			objects[i]->getSprite().setPosition(objects[i]->getBody()->getPos());
			objects[i]->render(rWindow);
		}
	}

	//pSystem.debugRender(rWindow);
	guiSystem.render(rWindow);


}

Spieler * Spielfeld::getPlayer()
{
	return player;
}

PhysicsSystem * Spielfeld::getPhysicsSystem()
{
	return &pSystem;
}

sf::RenderTexture * Spielfeld::getBackgroundTexture()
{
	return &backgound;
}

void Spielfeld::updateBackground()
{
	backgound.display();
}