﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SnakeGameMode.generated.h"

/**
 * 
 */
class ASnakePart;
UCLASS()
class TEST0614_API ASnakeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// 시작하면서 맵의 외곽 벽을 만들고 맵을 정의하는 함수
	UFUNCTION(BlueprintCallable)
	void CreateOutWall(int _Y, int _Z, FVector _TileSize, TSubclassOf<AActor> _WallType);

	FORCEINLINE FVector GetTileSize()
	{
		return TileSize;
	}

	FORCEINLINE FIntVector3 GetCount()
	{
		return TileCount;
	}

	void SetPart(class AActor* _Part);

	void SetPart(int _Y, int _Z, class AActor* _Part);

	bool IsPart(FVector _Pos, FName _Tag);

	bool IsPart(int _Y, int _Z, FName _Tag);

	AActor* GetPart(FVector _Pos, FName _Tag);

	AActor* GetPart(int _Y, int _Z, FName _Tag);

	void AddBody(ASnakePart* head);

	void CurBodyReset();

protected:
	void BeginPlay() override;
	void Tick(float _Delta) override;

private:
	FVector TileSize;
	FIntVector3 TileCount;
	TArray<TArray<class AActor*>> AllMapActor;

	void AllMapClear();

	AActor* CurBody = nullptr;

	FRandomStream RandomCreate = FRandomStream();


	// 이번에는 변수를 블루프린트에서 세팅하고 변경하고 싶다.
	UPROPERTY(Category = "GameModeValue", EditAnywhere, DisplayName = "바디 오브젝트 클래스")
		TSubclassOf<AActor> BodyType;

	UPROPERTY(Category = "GameModeValue", EditAnywhere, DisplayName = "바디 아이템 클래스")
		TSubclassOf<AActor> BodyItemType;
};
