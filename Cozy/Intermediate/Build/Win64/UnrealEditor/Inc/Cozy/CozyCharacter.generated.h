// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COZY_CozyCharacter_generated_h
#error "CozyCharacter.generated.h already included, missing '#pragma once' in CozyCharacter.h"
#endif
#define COZY_CozyCharacter_generated_h

#define Cozy_Source_Cozy_CozyCharacter_h_12_SPARSE_DATA
#define Cozy_Source_Cozy_CozyCharacter_h_12_RPC_WRAPPERS
#define Cozy_Source_Cozy_CozyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Cozy_Source_Cozy_CozyCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACozyCharacter(); \
	friend struct Z_Construct_UClass_ACozyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACozyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cozy"), NO_API) \
	DECLARE_SERIALIZER(ACozyCharacter)


#define Cozy_Source_Cozy_CozyCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACozyCharacter(); \
	friend struct Z_Construct_UClass_ACozyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACozyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cozy"), NO_API) \
	DECLARE_SERIALIZER(ACozyCharacter)


#define Cozy_Source_Cozy_CozyCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACozyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACozyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACozyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACozyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACozyCharacter(ACozyCharacter&&); \
	NO_API ACozyCharacter(const ACozyCharacter&); \
public:


#define Cozy_Source_Cozy_CozyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACozyCharacter(ACozyCharacter&&); \
	NO_API ACozyCharacter(const ACozyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACozyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACozyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACozyCharacter)


#define Cozy_Source_Cozy_CozyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ACozyCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ACozyCharacter, FollowCamera); }


#define Cozy_Source_Cozy_CozyCharacter_h_9_PROLOG
#define Cozy_Source_Cozy_CozyCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Cozy_Source_Cozy_CozyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Cozy_Source_Cozy_CozyCharacter_h_12_SPARSE_DATA \
	Cozy_Source_Cozy_CozyCharacter_h_12_RPC_WRAPPERS \
	Cozy_Source_Cozy_CozyCharacter_h_12_INCLASS \
	Cozy_Source_Cozy_CozyCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Cozy_Source_Cozy_CozyCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Cozy_Source_Cozy_CozyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Cozy_Source_Cozy_CozyCharacter_h_12_SPARSE_DATA \
	Cozy_Source_Cozy_CozyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Cozy_Source_Cozy_CozyCharacter_h_12_INCLASS_NO_PURE_DECLS \
	Cozy_Source_Cozy_CozyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COZY_API UClass* StaticClass<class ACozyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Cozy_Source_Cozy_CozyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
