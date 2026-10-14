/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GameDefines.hpp
# ========================================================================================= #
# Credits: ItsBranK, TheFeckless
# Links: www.github.com/CodeRedModding/CodeRed-Generator
#############################################################################################
*/
#pragma once
#include <windows.h>
#include <algorithm>
#include <locale>
#include <stdlib.h>
#include <xlocale>
#include <ctype.h>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <unordered_map>

/*
# ========================================================================================= #
# Flags
# ========================================================================================= #
*/

// https://github.com/CodeRedModding/UnrealEngine3/blob/main/Development/Src/Core/Inc/UnStack.h#L48
// State Flags
enum EStateFlags
{
	STATE_Editable =						0x00000001,	// State should be user-selectable in UnrealEd.
	STATE_Auto =							0x00000002,	// State is automatic (the default state).
	STATE_Simulated =						0x00000004, // State executes on client side.
	STATE_HasLocals =						0x00000008,	// State has local variables.
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/main/Development/Src/Core/Inc/UnStack.h#L60
// Function Flags
enum EFunctionFlags : uint64_t
{
	FUNC_Final =							0x00000001, // Function is final (prebindable, non-overridable function).
	FUNC_Defined =							0x00000002, // Function has been defined (not just declared).
	FUNC_Iterator =							0x00000004, // Function is an iterator.
	FUNC_Latent =							0x00000008, // Function is a latent state function.
	FUNC_PreOperator =						0x00000010, // Unary operator is a prefix operator.
	FUNC_Singular =							0x00000020, // Function cannot be reentered.
	FUNC_Net =								0x00000040, // Function is network-replicated.
	FUNC_NetReliable =						0x00000080, // Function should be sent reliably on the network.
	FUNC_Simulated =						0x00000100, // Function executed on the client side.
	FUNC_Exec =								0x00000200, // Executable from command line.
	FUNC_Native =							0x00000400, // Native function.
	FUNC_Event =							0x00000800, // Event function.
	FUNC_Operator =							0x00001000, // Operator function.
	FUNC_Static =							0x00002000, // Static function.
	FUNC_OptionalParm =						0x00004000, // Function has optional parameters.
	FUNC_Const =							0x00008000, // Function doesn't modify this object.
	FUNC_Invariant =						0x00010000, // Unused.
	FUNC_Public =							0x00020000, // Function is accessible in all classes (if overridden, parameters much remain unchanged).
	FUNC_Private =							0x00040000, // Function is accessible only in the class it is defined in (cannot be overriden, but function name may be reused in subclasses. IOW: if overridden, parameters don't need to match, and Super.Func() cannot be accessed since it's private.).
	FUNC_Protected =						0x00080000, // Function is accessible only in the class it is defined in and subclasses (if overridden, parameters much remain unchanged).
	FUNC_Delegate =							0x00100000, // Function is actually a delegate.
	FUNC_NetServer =						0x00200000, // Function is executed on servers (set by replication code if passes check).
	FUNC_HasOutParms =						0x00400000, // Function has out (pass by reference) parameters.
	FUNC_HasDefaults =						0x00800000, // Function has structs that contain defaults.
	FUNC_NetClient =						0x01000000, // Function is executed on clients.
	FUNC_DLLImport =						0x02000000, // Function is imported from a DLL.

	FUNC_K2Call =							0x04000000,
	FUNC_K2Override =						0x08000000,
	FUNC_K2Pure =							0x10000000,
	FUNC_EditorOnly =						0x20000000,
	FUNC_Lambda =							0x40000000,
	FUNC_NetValidate =						0x80000000,

	FUNC_FuncInherit =						(FUNC_Exec | FUNC_Event),
	FUNC_FuncOverrideMatch =				(FUNC_Exec | FUNC_Final | FUNC_Latent | FUNC_PreOperator | FUNC_Iterator | FUNC_Static | FUNC_Public | FUNC_Protected | FUNC_Const),
	FUNC_NetFuncFlags =						(FUNC_Net | FUNC_NetReliable | FUNC_NetServer | FUNC_NetClient),

	FUNC_AllFlags =							0xFFFFFFFF
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/main/Development/Src/Core/Inc/UnObjBas.h#L238
// Proprerty Flags
enum EPropertyFlags : uint64_t
{
	CPF_Edit =								0x0000000000000001,	// Property is user-settable in the editor.
	CPF_Const =								0x0000000000000002,	// Actor's property always matches class's default actor property.
	CPF_Input =								0x0000000000000004,	// Variable is writable by the input system.
	CPF_ExportObject =						0x0000000000000008,	// Object can be exported with actor.
	CPF_OptionalParm =						0x0000000000000010,	// Optional parameter (if CPF_Param is set).
	CPF_Net =								0x0000000000000020,	// Property is relevant to network replication.
	CPF_EditFixedSize =						0x0000000000000040, // Indicates that elements of an array can be modified, but its size cannot be changed.
	CPF_Parm =								0x0000000000000080,	// Function/When call parameter.
	CPF_OutParm =							0x0000000000000100,	// Value is copied out after function call.
	CPF_SkipParm =							0x0000000000000200,	// Property is a short-circuitable evaluation function parm.
	CPF_ReturnParm =						0x0000000000000400,	// Return value.
	CPF_CoerceParm =						0x0000000000000800,	// Coerce args into this function parameter.
	CPF_Native =							0x0000000000001000,	// Property is native: C++ code is responsible for serializing it.
	CPF_Transient =							0x0000000000002000,	// Property is transient: shouldn't be saved, zero-filled at load time.
	CPF_Config =							0x0000000000004000,	// Property should be loaded/saved as permanent profile.
	CPF_Localized =							0x0000000000008000,	// Property should be loaded as localizable text.
	CPF_Travel =							0x0000000000010000,	// Property travels across levels/servers.
	CPF_EditConst =							0x0000000000020000,	// Property is uneditable in the editor.
	CPF_GlobalConfig =						0x0000000000040000,	// Load config from base class, not subclass.
	CPF_Component =							0x0000000000080000,	// Property containts component references.
	CPF_AlwaysInit =						0x0000000000100000,	// Property should never be exported as NoInit(@todo - this doesn't need to be a property flag...only used during make).
	CPF_DuplicateTransient =				0x0000000000200000, // Property should always be reset to the default value during any type of duplication (copy/paste, binary duplication, etc.).
	CPF_NeedCtorLink =						0x0000000000400000,	// Fields need construction/destruction.
	CPF_NoExport =							0x0000000000800000,	// Property should not be exported to the native class header file.
	CPF_NoClear =							0x0000000002000000,	// Hide clear (and browse) button.
	CPF_EditInline =						0x0000000004000000,	// Edit this object reference inline.	
	CPF_EditInlineUse =						0x0000000010000000,	// EditInline with Use button.
	CPF_EditFindable =						0x0000000008000000,	// References are set by clicking on actors in the editor viewports.
	CPF_Deprecated =						0x0000000020000000,	// Property is deprecated.  Read it from an archive, but don't save it.	
	CPF_DataBinding =						0x0000000040000000,	// Indicates that this property should be exposed to data stores.
	CPF_SerializeText =						0x0000000080000000,	// Native property should be serialized as text (ImportText, ExportText).
	CPF_RepNotify =							0x0000000100000000,	// Notify actors when a property is replicated.
	CPF_Interp =							0x0000000200000000,	// Interpolatable property for use with matinee.
	CPF_NonTransactional =					0x0000000400000000,	// Property isn't transacted.
	CPF_EditorOnly =						0x0000000800000000,	// Property should only be loaded in the editor.
	CPF_NotForConsole =						0x0000001000000000, // Property should not be loaded on console (or be a console cooker commandlet).
	CPF_RepRetry =							0x0000002000000000, // Property replication of this property if it fails to be fully sent (e.g. object references not yet available to serialize over the network).
	CPF_PrivateWrite =						0x0000004000000000, // Property is const outside of the class it was declared in.
	CPF_ProtectedWrite =					0x0000008000000000, // Property is const outside of the class it was declared in and subclasses.
	CPF_ArchetypeProperty =					0x0000010000000000, // Property should be ignored by archives which have ArIgnoreArchetypeRef set.
	CPF_EditHide =							0x0000020000000000, // Property should never be shown in a properties window.
	CPF_EditTextBox =						0x0000040000000000, // Property can be edited using a text dialog box.
	CPF_CrossLevelPassive =					0x0000100000000000, // Property can point across levels, and will be serialized properly, but assumes it's target exists in-game (non-editor)
	CPF_CrossLevelActive =					0x0000200000000000, // Property can point across levels, and will be serialized properly, and will be updated when the target is streamed in/out
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/main/Development/Src/Core/Inc/UnObjBas.h#L316
// Object Flags
enum EObjectFlags : uint64_t
{
	RF_InSingularFunc =						0x0000000000000002,	// In a singular function.
	RF_StateChanged =						0x0000000000000004,	// Object did a state change.
	RF_DebugPostLoad =						0x0000000000000008,	// For debugging PostLoad calls.
	RF_DebugSerialize =						0x0000000000000010,	// For debugging Serialize calls.
	RF_DebugFinishDestroyed =				0x0000000000000020,	// For debugging FinishDestroy calls.
	RF_EdSelected =							0x0000000000000040,	// Object is selected in one of the editors browser windows.
	RF_ZombieComponent =					0x0000000000000080,	// This component's template was deleted, so should not be used.
	RF_Protected =							0x0000000000000100, // Property is protected (may only be accessed from its owner class or subclasses).
	RF_ClassDefaultObject =					0x0000000000000200,	// this object is its class's default object.
	RF_ArchetypeObject =					0x0000000000000400, // this object is a template for another object (treat like a class default object).
	RF_ForceTagExp =						0x0000000000000800, // Forces this object to be put into the export table when saving a package regardless of outer.
	RF_TokenStreamAssembled =				0x0000000000001000, // Set if reference token stream has already been assembled.
	RF_MisalignedObject =					0x0000000000002000, // Object's size no longer matches the size of its C++ class (only used during make, for native classes whose properties have changed).
	RF_RootSet =							0x0000000000004000, // Object will not be garbage collected, even if unreferenced.
	RF_BeginDestroyed =						0x0000000000008000,	// BeginDestroy has been called on the object.
	RF_FinishDestroyed =					0x0000000000010000, // FinishDestroy has been called on the object.
	RF_DebugBeginDestroyed =				0x0000000000020000, // Whether object is rooted as being part of the root set (garbage collection).
	RF_MarkedByCooker =						0x0000000000040000,	// Marked by content cooker.
	RF_LocalizedResource =					0x0000000000080000, // Whether resource object is localized.
	RF_InitializedProps =					0x0000000000100000, // whether InitProperties has been called on this object
	RF_PendingFieldPatches =				0x0000000000200000, // @script patcher: indicates that this struct will receive additional member properties from the script patcher.
	RF_IsCrossLevelReferenced =				0x0000000000400000,	// This object has been pointed to by a cross-level reference, and therefore requires additional cleanup upon deletion.
	RF_Saved =								0x0000000080000000, // Object has been saved via SavePackage (temporary).
	RF_Transactional =						0x0000000100000000, // Object is transactional.
	RF_Unreachable =						0x0000000200000000, // Object is not reachable on the object graph.
	RF_Public =								0x0000000400000000, // Object is visible outside its package.
	RF_TagImp =								0x0000000800000000,	// Temporary import tag in load/save.
	RF_TagExp =								0x0000001000000000,	// Temporary export tag in load/save.
	RF_Obsolete =							0x0000002000000000, // Object marked as obsolete and should be replaced.
	RF_TagGarbage =							0x0000004000000000,	// Check during garbage collection.
	RF_DisregardForGC =						0x0000008000000000,	// Object is being disregard for GC as its static and itself and all references are always loaded.
	RF_PerObjectLocalized =					0x0000010000000000,	// Object is localized by instance name, not by class.
	RF_NeedLoad =							0x0000020000000000, // During load, indicates object needs loading.
	RF_AsyncLoading =						0x0000040000000000, // Object is being asynchronously loaded.
	RF_NeedPostLoadSubobjects =				0x0000080000000000, // During load, indicates that the object still needs to instance subobjects and fixup serialized component references.
	RF_Suppress =							0x0000100000000000, // @warning: Mirrored in UnName.h. Suppressed log name.
	RF_InEndState =							0x0000200000000000, // Within an EndState call.
	RF_Transient =							0x0000400000000000, // Don't save object.
	RF_Cooked =								0x0000800000000000, // Whether the object has already been cooked
	RF_LoadForClient =						0x0001000000000000, // In-file load for client.
	RF_LoadForServer =						0x0002000000000000, // In-file load for client.
	RF_LoadForEdit =						0x0004000000000000, // In-file load for client.
	RF_Standalone =							0x0008000000000000,	// Keep object around for editing even if unreferenced.
	RF_NotForClient =						0x0010000000000000, // Don't load this object for the game client.
	RF_NotForServer =						0x0020000000000000, // Don't load this object for the game server.
	RF_NotForEdit =							0x0040000000000000,	// Don't load this object for the editor.
	RF_NeedPostLoad =						0x0100000000000000, // Object needs to be postloaded.
	RF_HasStack =							0x0200000000000000, // Has execution stack.
	RF_Native =								0x0400000000000000, // Native (UClass only)
	RF_Marked =								0x0800000000000000,	// Marked (for debugging).
	RF_ErrorShutdown =						0x1000000000000000, // ShutdownAfterError called.
	RF_PendingKill =						0x2000000000000000, // Objects that are pending destruction (invalid for gameplay but valid objects).
	RF_MarkedByCookerTemp =					0x4000000000000000,	// Temporarily marked by content cooker (should be cleared).
	RF_CookedStartupObject =				0x8000000000000000, // This object was cooked into a startup package.

	RF_ContextFlags =						(RF_NotForClient | RF_NotForServer | RF_NotForEdit), // All context flags.
	RF_LoadContextFlags =					(RF_LoadForClient | RF_LoadForServer | RF_LoadForEdit), // Flags affecting loading.
	RF_Load =								(RF_ContextFlags | RF_LoadContextFlags | RF_Public | RF_Standalone | RF_Native | RF_Obsolete | RF_Protected | RF_Transactional | RF_HasStack | RF_PerObjectLocalized | RF_ClassDefaultObject | RF_ArchetypeObject | RF_LocalizedResource), // Flags to load from Unrealfiles.
	RF_Keep =								(RF_Native | RF_Marked | RF_PerObjectLocalized | RF_MisalignedObject | RF_DisregardForGC | RF_RootSet | RF_LocalizedResource), // Flags to persist across loads.
	RF_ScriptMask =							(RF_Transactional | RF_Public | RF_Transient | RF_NotForClient | RF_NotForServer | RF_NotForEdit | RF_Standalone), // Script-accessible flags.
	RF_UndoRedoMask =						(RF_PendingKill), // Undo/ redo will store/ restore these
	RF_PropagateToSubObjects =				(RF_Public | RF_ArchetypeObject | RF_Transactional), // Sub-objects will inherit these flags from their SuperObject.

	RF_AllFlags =							0xFFFFFFFFFFFFFFFF,
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/main/Development/Src/Core/Inc/UnObjBas.h#L51
// Package Flags
enum EPackageFlags : uint32_t
{
	PKG_AllowDownload =						0x00000001,	// Allow downloading package.
	PKG_ClientOptional =					0x00000002,	// Purely optional for clients.
	PKG_ServerSideOnly =					0x00000004, // Only needed on the server side.
	PKG_Cooked =							0x00000008,	// Whether this package has been cooked for the target platform.
	PKG_Unsecure =							0x00000010, // Not trusted.
	PKG_SavedWithNewerVersion =				0x00000020,	// Package was saved with newer version.
	PKG_Need =								0x00008000,	// Client needs to download this package.
	PKG_Compiling =							0x00010000,	// package is currently being compiled
	PKG_ContainsMap =						0x00020000,	// Set if the package contains a ULevel/ UWorld object
	PKG_Trash =								0x00040000,	// Set if the package was loaded from the trashcan
	PKG_DisallowLazyLoading =				0x00080000,	// Set if the archive serializing this package cannot use lazy loading
	PKG_PlayInEditor =						0x00100000,	// Set if the package was created for the purpose of PIE
	PKG_ContainsScript =					0x00200000,	// Package is allowed to contain UClasses and unrealscript
	PKG_ContainsDebugInfo =					0x00400000,	// Package contains debug info (for UDebugger)
	PKG_RequireImportsAlreadyLoaded =		0x00800000,	// Package requires all its imports to already have been loaded
	PKG_StoreCompressed =					0x02000000,	// Package is being stored compressed, requires archive support for compression
	PKG_StoreFullyCompressed =				0x04000000,	// Package is serialized normally, and then fully compressed after (must be decompressed before LoadPackage is called)
	PKG_ContainsFaceFXData =				0x10000000,	// Package contains FaceFX assets and/or animsets
	PKG_NoExportAllowed =					0x20000000,	// Package was NOT created by a modder.  Internal data not for export
	PKG_StrippedSource =					0x40000000,	// Source has been removed to compress the package size
	PKG_FilterEditorOnly =					0x80000000,	// Package has editor-only data filtered
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/7bf53e29f620b0d4ca5c9bd063a2d2dbcee732fe/Development/Src/Core/Inc/UnObjBas.h#L98
// Class Flags
enum EClassFlags : uint32_t
{
	CLASS_None =							0x00000000, 
	CLASS_Abstract =						0x00000001, // Class is abstract and can't be instantiated directly.
	CLASS_Compiled =						0x00000002, // Script has been compiled successfully.
	CLASS_Config =							0x00000004, // Load object configuration at construction time.
	CLASS_Transient =						0x00000008, // This object type can't be saved; null it out at save time.
	CLASS_Parsed =							0x00000010, // Successfully parsed.
	CLASS_Localized =						0x00000020, // Class contains localized text.
	CLASS_SafeReplace =						0x00000040, // Objects of this class can be safely replaced with default or NULL.
	CLASS_Native =							0x00000080, // Class is a native class - native interfaces will have CLASS_Native set, but not RF_Native.
	CLASS_NoExport =						0x00000100, // Don't export to C++ header.
	CLASS_Placeable =						0x00000200, // Allow users to create in the editor.
	CLASS_PerObjectConfig =					0x00000400, // Handle object configuration on a per-object basis, rather than per-class.
	CLASS_NativeReplication =				0x00000800, // Replication handled in C++.
	CLASS_EditInlineNew =					0x00001000, // Class can be constructed from editinline New button..
	CLASS_CollapseCategories =				0x00002000,	// Display properties in the editor without using categories.
	CLASS_Interface =						0x00004000, // Class is an interface.
	CLASS_HasInstancedProps =				0x00200000, // class contains object properties which are marked "instanced" (or editinline export).
	CLASS_NeedsDefProps =					0x00400000, // Class needs its defaultproperties imported.
	CLASS_HasComponents =					0x00800000, // Class has component properties.
	CLASS_Hidden =							0x01000000, // Don't show this class in the editor class browser or edit inline new menus.
	CLASS_Deprecated =						0x02000000, // Don't save objects of this class when serializing.
	CLASS_HideDropDown =					0x04000000, // Class not shown in editor drop down for class selection.
	CLASS_Exported =						0x08000000, // Class has been exported to a header file.
	CLASS_Intrinsic =						0x10000000, // Class has no unrealscript counter-part.
	CLASS_NativeOnly =						0x20000000, // Properties in this class can only be accessed from native code.
	CLASS_PerObjectLocalized =				0x40000000, // Handle object localization on a per-object basis, rather than per-class. 
	CLASS_HasCrossLevelRefs =				0x80000000, // This class has properties that are marked with CPF_CrossLevel 

	// Deprecated, these values now match the values of the EClassCastFlags enum.
	CLASS_IsAUProperty =					0x00008000,
	CLASS_IsAUObjectProperty =				0x00010000,
	CLASS_IsAUBoolProperty =				0x00020000,
	CLASS_IsAUState =						0x00040000,
	CLASS_IsAUFunction =					0x00080000,
	CLASS_IsAUStructProperty =				0x00100000,

	// Flags to inherit from base class.
	CLASS_Inherit =							(CLASS_Transient | CLASS_Config | CLASS_Localized | CLASS_SafeReplace | CLASS_PerObjectConfig | CLASS_PerObjectLocalized | CLASS_Placeable | CLASS_IsAUProperty | CLASS_IsAUObjectProperty | CLASS_IsAUBoolProperty | CLASS_IsAUStructProperty | CLASS_IsAUState | CLASS_IsAUFunction | CLASS_HasComponents | CLASS_Deprecated | CLASS_Intrinsic | CLASS_HasInstancedProps | CLASS_HasCrossLevelRefs),

	// These flags will be cleared by the compiler when the class is parsed during script compilation.
	CLASS_RecompilerClear =					(CLASS_Inherit | CLASS_Abstract | CLASS_NoExport | CLASS_NativeReplication | CLASS_Native),

	// These flags will be inherited from the base class only for non-intrinsic classes.
	CLASS_ScriptInherit =					(CLASS_Inherit | CLASS_EditInlineNew | CLASS_CollapseCategories),

	CLASS_AllFlags =						0xFFFFFFFF,
};

// https://github.com/CodeRedModding/UnrealEngine3/blob/7bf53e29f620b0d4ca5c9bd063a2d2dbcee732fe/Development/Src/Core/Inc/UnObjBas.h#L195
// Class Cast Flags
enum EClassCastFlag : uint32_t
{
	CASTCLASS_None =						0x00000000,
	CASTCLASS_UField =						0x00000001,
	CASTCLASS_UConst =						0x00000002,
	CASTCLASS_UEnum =						0x00000004,
	CASTCLASS_UStruct =						0x00000008,
	CASTCLASS_UScriptStruct =				0x00000010,
	CASTCLASS_UClass =						0x00000020,
	CASTCLASS_UByteProperty =				0x00000040,
	CASTCLASS_UIntProperty =				0x00000080,
	CASTCLASS_UFloatProperty =				0x00000100,
	CASTCLASS_UComponentProperty =			0x00000200,
	CASTCLASS_UClassProperty =				0x00000400,
	CASTCLASS_UInterfaceProperty =			0x00001000,
	CASTCLASS_UNameProperty =				0x00002000,
	CASTCLASS_UStrProperty =				0x00004000,

	// These match the values of the old class flags to make conversion easier.
	CASTCLASS_UProperty =					0x00008000,
	CASTCLASS_UObjectProperty =				0x00010000,
	CASTCLASS_UBoolProperty =				0x00020000,
	CASTCLASS_UState =						0x00040000,
	CASTCLASS_UFunction =					0x00080000,
	CASTCLASS_UStructProperty =				0x00100000,

	CASTCLASS_UArrayProperty =				0x00200000,
	CASTCLASS_UMapProperty =				0x00400000,
	CASTCLASS_UDelegateProperty =			0x00800000,
	CASTCLASS_UComponent =					0x01000000,

	CASTCLASS_AllFlags =					0xFFFFFFFF,
};

/*
# ========================================================================================= #
# Globals
# ========================================================================================= #
*/

// GObjects
#define GObjects_Offset		(uintptr_t)0x10723F8
// GNames
#define GNames_Offset		(uintptr_t)0x10723A4

enum class EGameBuild : int32_t
{
	Main = 0,
	EA = 1,
	Steam = 2,
	AutoDetect = -1
};

struct FGameBuildOffsets
{
	const char* Name;
	uintptr_t GObjectsOffset;
	uintptr_t GNamesOffset;
};

static constexpr FGameBuildOffsets GGameBuilds[] =
{
	{ "Main", (uintptr_t)0x10723F8, (uintptr_t)0x10723A4 },
	{ "EA", (uintptr_t)0x10F6CE0, (uintptr_t)0x10F6D00 },
	{ "Steam", (uintptr_t)0x10F6CE0, (uintptr_t)0x10F6D00 },
};

/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

template<typename TArray>
class TIterator
{
public:
	using ElementType = typename TArray::ElementType;
	using ElementPointer = ElementType*;
	using ElementReference = ElementType&;
	using ElementConstReference = const ElementType&;

private:
	ElementPointer IteratorData;

public:
	TIterator(ElementPointer inElementPointer) : IteratorData(inElementPointer) {}

	~TIterator() {}

public:
	TIterator& operator++()
	{
		IteratorData++;
		return *this;
	}

	TIterator operator++(int32_t)
	{
		TIterator iteratorCopy = *this;
		++(*this);
		return iteratorCopy;
	}

	TIterator& operator--()
	{
		IteratorData--;
		return *this;
	}

	TIterator operator--(int32_t)
	{
		TIterator iteratorCopy = *this;
		--(*this);
		return iteratorCopy;
	}

	ElementReference operator[](int32_t index)
	{
		return *(IteratorData[index]);
	}

	ElementPointer operator->()
	{
		return IteratorData;
	}

	ElementReference operator*()
	{
		return *IteratorData;
	}

public:
	bool operator==(const TIterator& other) const
	{
		return (IteratorData == other.IteratorData);
	}

	bool operator!=(const TIterator& other) const
	{
		return !(*this == other);
	}
};

template<typename InElementType>
class TArray
{
public:
	using ElementType = InElementType;
	using ElementPointer = ElementType*;
	using ElementReference = ElementType&;
	using ElementConstPointer = const ElementType*;
	using ElementConstReference = const ElementType&;
	using Iterator = TIterator<TArray<ElementType>>;

private:
	ElementPointer ArrayData;
	int32_t ArrayCount;
	int32_t ArrayMax;

public:
	TArray() : ArrayData(nullptr), ArrayCount(0), ArrayMax(0)
	{
		//ReAllocate(sizeof(ElementType));
	}

	~TArray()
	{
		//clear();
		//::operator delete(ArrayData, ArrayMax * sizeof(ElementType));
	}

public:
	ElementConstReference operator[](int32_t index) const
	{
		return ArrayData[index];
	}

	ElementReference operator[](int32_t index)
	{
		return ArrayData[index];
	}

	ElementConstReference at(int32_t index) const
	{
		return ArrayData[index];
	}

	ElementReference at(int32_t index)
	{
		return ArrayData[index];
	}

	ElementConstPointer data() const
	{
		return ArrayData;
	}

	void push_back(ElementConstReference newElement)
	{
		if (ArrayCount >= ArrayMax)
		{
			ReAllocate(sizeof(ElementType) * (ArrayCount + 1));
		}

		new(&ArrayData[ArrayCount]) ElementType(newElement);
		ArrayCount++;
	}

	void push_back(ElementReference& newElement)
	{
		if (ArrayCount >= ArrayMax)
		{
			ReAllocate(sizeof(ElementType) * (ArrayCount + 1));
		}

		new(&ArrayData[ArrayCount]) ElementType(newElement);
		ArrayCount++;
	}

	void pop_back()
	{
		if (ArrayCount > 0)
		{
			ArrayCount--;
			ArrayData[ArrayCount].~ElementType();
		}
	}

	void clear()
	{
		for (int32_t i = 0; i < ArrayCount; i++)
		{
			ArrayData[i].~ElementType();
		}

		ArrayCount = 0;
	}

	int32_t size() const
	{
		return ArrayCount;
	}

	int32_t capacity() const
	{
		return ArrayMax;
	}

	bool IsValidIndex(int32_t index) const
	{
		return ((index >= 0) && (index < ArrayCount));
	}

	bool empty() const
	{
		if (ArrayData)
		{
			return (size() == 0);
		}

		return true;
	}

	Iterator begin()
	{
		return Iterator(ArrayData);
	}

	Iterator end()
	{
		return Iterator(ArrayData + ArrayCount);
	}

private:
	void ReAllocate(int32_t newArrayMax)
	{
		ElementPointer newArrayData = (ElementPointer)::operator new(newArrayMax * sizeof(ElementType));
		int32_t newNum = ArrayCount;

		if (newArrayMax < newNum)
		{
			newNum = newArrayMax;
		}

		for (int32_t i = 0; i < newNum; i++)
		{
			new(newArrayData + i) ElementType(std::move(ArrayData[i]));
		}

		for (int32_t i = 0; i < ArrayCount; i++)
		{
			ArrayData[i].~ElementType();
		}

		::operator delete(ArrayData, ArrayMax * sizeof(ElementType));
		ArrayData = newArrayData;
		ArrayMax = newArrayMax;
	}
};

template<typename TKey, typename TValue>
class TMap
{
private:
	struct TPair
	{
		TKey Key;
		TValue Value;
		int32_t* HashNext;
	};

public:
	using ElementType = TPair;
	using ElementPointer = ElementType*;
	using ElementReference = ElementType&;
	using ElementConstReference = const ElementType&;
	using Iterator = TIterator<class TArray<ElementType>>;

public:
	class TArray<ElementType> Elements;								// 0x0000 (0x000C)
	struct FPointer IndirectData;									// 0x000C (0x0004)
	int32_t InlineData[0x4];										// 0x0010 (0x0010)
	int32_t NumBits;												// 0x0020 (0x0004)
	int32_t MaxBits;												// 0x0024 (0x0004)
	int32_t FirstFreeIndex;											// 0x0028 (0x0004)
	int32_t NumFreeIndices;											// 0x002C (0x0004)
	struct FPointer Hash;											// 0x0030 (0x0004)
	int32_t InlineHash;												// 0x0034 (0x0004)
	int32_t HashSize;												// 0x0038 (0x0004)

public:
	TMap() :
		IndirectData(NULL),
		NumBits(0),
		MaxBits(0),
		FirstFreeIndex(0),
		NumFreeIndices(0),
		Hash(nullptr),
		InlineHash(0),
		HashSize(0)
	{

	}

	TMap(struct FMap_Mirror& other) :
		IndirectData(NULL),
		NumBits(0),
		MaxBits(0),
		FirstFreeIndex(0),
		NumFreeIndices(0),
		Hash(nullptr),
		InlineHash(0),
		HashSize(0)
	{
		assign(other);
	}

	TMap(const TMap<TKey, TValue>& other) :
		IndirectData(NULL),
		NumBits(0),
		MaxBits(0),
		FirstFreeIndex(0),
		NumFreeIndices(0),
		Hash(nullptr),
		InlineHash(0),
		HashSize(0)
	{
		assign(other);
	}

	~TMap() {}

public:
	TMap<TKey, TValue>& assign(struct FMap_Mirror& other)
	{
		*this = *reinterpret_cast<TMap<TKey, TValue>*>(&other);
		return *this;
	}

	TMap<TKey, TValue>& assign(const TMap<TKey, TValue>& other)
	{
		Elements = other.Elements;
		IndirectData = other.IndirectData;
		InlineData[0] = other.InlineData[0];
		InlineData[1] = other.InlineData[1];
		InlineData[2] = other.InlineData[2];
		InlineData[3] = other.InlineData[3];
		NumBits = other.NumBits;
		MaxBits = other.MaxBits;
		FirstFreeIndex = other.FirstFreeIndex;
		NumFreeIndices = other.NumFreeIndices;
		Hash = other.Hash;
		InlineHash = other.InlineHash;
		HashSize = other.HashSize;
		return *this;
	}

	TValue& at(const TKey& key)
	{
		for (TPair& pair : Elements)
		{
			if (pair.Key == key)
			{
				return pair.Value;
			}
		}
	}

	const TValue& at(const TKey& key) const
	{
		for (const TPair& pair : Elements)
		{
			if (pair.Key == key)
			{
				return pair.Value;
			}
		}
	}

	TPair& at_index(int32_t index)
	{
		return Elements[index];
	}

	const TPair& at_index(int32_t index) const
	{
		return Elements[index];
	}

	int32_t size() const
	{
		return Elements.size();
	}

	int32_t capacity() const
	{
		return Elements.capacity();
	}

	bool empty() const
	{
		return Elements.empty();
	}

	Iterator begin()
	{
		return Elements.begin();
	}

	Iterator end()
	{
		return Elements.end();
	}

public:
	TValue& operator[](const TKey& key)
	{
		return at(key);
	}

	const TValue& operator[](const TKey& key) const
	{
		return at(key);
	}

	TMap<TKey, TValue>& operator=(const struct FMap_Mirror& other)
	{
		return assign(other);
	}

	TMap<TKey, TValue>& operator=(const TMap<TKey, TValue>& other)
	{
		return assign(other);
	}
};

extern class TArray<class UObject*>* GObjects;
extern class TArray<class FNameEntry*>* GNames;

namespace SDKLoader
{
	bool AreGObjectsValid();
	bool AreGNamesValid();
	bool AreGlobalsValid();

	int32_t GetLoadedBuild();
	const char* GetLoadedBuildName();

	bool Initialize(EGameBuild gameBuild = EGameBuild::AutoDetect, uint32_t timeoutMs = 1000);
}

/*
# ========================================================================================= #
# Structs
# ========================================================================================= #
*/

class FNameEntry
{
public:
	uint64_t Flags; // 0x0000 (0x0008)
	int32_t Index; // 0x0008 (0x0004)
	class FNameEntry* HashNext; // 0x000C (0x0004)
	char Name[0x400]; // 0x0010 (0x0001)

public:
	FNameEntry() : Flags(0), Index(-1), HashNext(nullptr) {}
	~FNameEntry() {}

public:
	uint64_t GetFlags() const
	{
		return Flags;
	}

	int32_t GetIndex() const
	{
		return Index;
	}

	const char* GetAnsiName() const
	{
		return Name;
	}

	bool IsWide() const
	{
		return ((Index & 1) != 0);
	}

	const wchar_t* GetWideName() const
	{
		return reinterpret_cast<const wchar_t*>(Name);
	}

	std::string ToString() const
	{
		if (IsWide())
		{
			int32_t neededSize = WideCharToMultiByte(CP_UTF8, 0, GetWideName(), -1, nullptr, 0, nullptr, nullptr);

			if (neededSize > 1)
			{
				std::string utf8Str(static_cast<size_t>(neededSize), '\0');
				WideCharToMultiByte(CP_UTF8, 0, GetWideName(), -1, &utf8Str[0], neededSize, nullptr, nullptr);
				utf8Str.pop_back();
				return utf8Str;
			}

			return "";
		}

		return std::string(Name);
	}
};

class FName
{
public:
	using ElementType = const char;
	using ElementPointer = ElementType*;

private:
	int32_t			FNameEntryId;									// 0x0000 (0x04)
	int32_t			InstanceNumber;									// 0x0004 (0x04)

public:
	FName() : FNameEntryId(-1), InstanceNumber(0) {}

	FName(int32_t id) : FNameEntryId(id), InstanceNumber(0) {}

	FName(ElementPointer nameToFind) : FNameEntryId(-1), InstanceNumber(0)
	{
		static std::unordered_map<std::string, int32_t> nameCache{};
		static int32_t scannedNames = 0;

		auto cachedName = nameCache.find(nameToFind);

		if (cachedName != nameCache.end())
		{
			FNameEntryId = cachedName->second;
			return;
		}

		if (!Names())
		{
			return;
		}

		for (; scannedNames < Names()->size(); scannedNames++)
		{
			FNameEntry* nameEntry = Names()->at(scannedNames);

			if (nameEntry && !nameEntry->IsWide())
			{
				nameCache.try_emplace(nameEntry->Name, scannedNames);
			}
		}

		cachedName = nameCache.find(nameToFind);

		if (cachedName != nameCache.end())
		{
			FNameEntryId = cachedName->second;
		}
	}

	FName(const FName& name) : FNameEntryId(name.FNameEntryId), InstanceNumber(name.InstanceNumber) {}

	~FName() {}

public:
	static TArray<FNameEntry*>* Names()
	{
		TArray<FNameEntry*>* recastedArray = reinterpret_cast<TArray<FNameEntry*>*>(GNames);
		return recastedArray;
	}

	int32_t GetDisplayIndex() const
	{
		return FNameEntryId;
	}

	const FNameEntry GetDisplayNameEntry() const
	{
		if (IsValid())
		{
			return *Names()->at(FNameEntryId);
		}

		return FNameEntry();
	}

	FNameEntry* GetEntry()
	{
		if (IsValid())
		{
			return Names()->at(FNameEntryId);
		}

		return nullptr;
	}

	int32_t GetInstance() const
	{
		return InstanceNumber;
	}

	void SetInstance(int32_t newNumber)
	{
		InstanceNumber = newNumber;
	}

	std::string ToString() const
	{
		if (IsValid())
		{
			std::string name = Names()->at(FNameEntryId)->ToString();

			if (InstanceNumber > 0)
			{
				name += ("_" + std::to_string(InstanceNumber - 1));
			}

			return name;
		}

		return "UnknownName";
	}

	bool IsValid() const
	{
		if (!Names() || (FNameEntryId < 0) || (FNameEntryId >= Names()->size()) || !Names()->at(FNameEntryId))
		{
			return false;
		}

		return true;
	}

public:
	FName& operator=(const FName& other)
	{
		FNameEntryId = other.FNameEntryId;
		InstanceNumber = other.InstanceNumber;
		return *this;
	}

	bool operator==(const FName& other) const
	{
		return ((FNameEntryId == other.FNameEntryId) && (InstanceNumber == other.InstanceNumber));
	}

	bool operator!=(const FName& other) const
	{
		return !(*this == other);
	}
};

class FString
{
public:
	using ElementType = const wchar_t;
	using ElementPointer = ElementType*;

private:
	ElementPointer	ArrayData;										// 0x0000 (0x08)
	int32_t			ArrayCount;										// 0x0008 (0x04)
	int32_t			ArrayMax;										// 0x000C (0x04)

public:
	FString() : ArrayData(nullptr), ArrayCount(0), ArrayMax(0) {}

	FString(ElementPointer other) : ArrayData(nullptr), ArrayCount(0), ArrayMax(0) { assign(other); }

	~FString() {}

public:
	FString& assign(ElementPointer other)
	{
		ArrayCount = (other ? (wcslen(other) + 1) : 0);
		ArrayMax = ArrayCount;
		ArrayData = (ArrayCount > 0 ? other : nullptr);
		return *this;
	}

	std::wstring ToWideString() const
	{
		if (!empty())
		{
			return std::wstring(c_str());
		}

		return L"";
	}

	std::string ToString() const
	{
		if (!empty())
		{
			std::wstring wideStr = ToWideString();

			if (!wideStr.empty())
			{
				int32_t neededSize = WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, nullptr, 0, nullptr, nullptr);

				if (neededSize > 1)
				{
					std::string utf8Str(static_cast<size_t>(neededSize), '\0');
					WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, &utf8Str[0], neededSize, nullptr, nullptr);
					utf8Str.pop_back();
					return utf8Str;
				}
			}
		}

		return "";
	}

	ElementPointer c_str() const
	{
		return ArrayData;
	}

	bool empty() const
	{
		if (ArrayData)
		{
			return (ArrayCount == 0);
		}

		return true;
	}

	int32_t length() const
	{
		return ArrayCount;
	}

	int32_t size() const
	{
		return ArrayMax;
	}

public:
	FString& operator=(ElementPointer other)
	{
		return assign(other);
	}

	FString& operator=(const FString& other)
	{
		return assign(other.c_str());
	}

	bool operator==(const FString& other)
	{
		if (!ArrayData || !other.ArrayData)
		{
			return (empty() == other.empty());
		}

		return (wcscmp(ArrayData, other.ArrayData) == 0);
	}

	bool operator!=(const FString& other)
	{
		return !(*this == other);
	}
};

struct FScriptDelegate
{
	class UObject* Object; // 0x0000 (0x04)
	class FName FunctionName; // 0x0000 (0x08)
};

struct FPointer
{
	uintptr_t Dummy; // 0x0000 (0x04)
};

struct FQWord
{
	int32_t A; // 0x0000 (0x04)
	int32_t B; // 0x0004 (0x04)
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/
