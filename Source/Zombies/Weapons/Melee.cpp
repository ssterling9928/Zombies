// Copyright © 2024 Stephen Sterling.  All rights reserved.  This software and its contents are protected by copyright law and international treaties.  Unauthorized copying, distribution, or use of any part of this project without express permission from Stephen Sterling is strictly prohibited.


#include "Melee.h"


// Sets default values
AMelee::AMelee()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMelee::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMelee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

