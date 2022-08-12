#include "../include/Bullet.h"


Bullet::Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation)
{
	generateGeometry();
	gameObject.setPosition(startingPosition);
	setBulletSpeed(startingVelocity, startingRotation);
	gameObject.screenWrap = true;
}

Bullet::Bullet(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float startingRotation, float _bulletSpeed)
{
	bulletSpeed = _bulletSpeed;
	gameObject.setPosition(startingPosition);

	setBulletSpeed(startingVelocity, startingRotation);
	gameObject.screenWrap = false;
	generateGeometry();
}

void Bullet::generateGeometry()
{
	//Definindo o tipo de linha
	objectVertexArr.setPrimitiveType(sf::Points);

	objectVertexArr.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::White));


	gameObject.vertexArr = objectVertexArr;
}

void Bullet::setBulletSpeed(sf::Vector2f startingVelocity, float startingRotation)
{
	gameObject.setRotation(startingRotation);

    double sinMultiplier = sin(gameObject.rotationRadians); // Eixo X
    double cosMultiplier = -cos(gameObject.rotationRadians); // Eixo y

    sf::Vector2f tempSpeedVector((sinMultiplier * bulletSpeed),(cosMultiplier * bulletSpeed));	
	gameObject.setSpeed(startingVelocity + tempSpeedVector);
}



void Bullet::process()
{
	gameObject.process();
}