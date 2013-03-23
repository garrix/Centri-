//
//  SystemInterfaces.h
//  Centri-
//
//  Created by Garrett Taiji on 3/12/13.
//
//
///

#ifndef __Centri___PlatformSystemInterfaces__
#define __Centri___PlatformSystemInterfaces__

#include <iostream>

/// Platform services
/// Provides Interfaces to feed and supply information
/// related to platform specific hardware and capabilities
///
/// Divide between platform specific user input devices?
/// Keyboards, Pointer, Multi-Touch Pointer, Controllers (xBox?), OtherInterface (Kinect?),
class IPlatformServicesUserInput{
    /// KeyBoard Data
    /// Pointer Data
    /// Multi-Touch Data
    /// Other Human Interface API
    
    /// Controller Data (too generic?)
    /// (joystick position, button presses, etc.)
    

    
};

class IDisplay{
    class IDisplaySpecs{
        
        /// change to Enum return type?
        /// store library of types with Specs
        /// about any given display
        virtual int Type();
        
    };
    
    
};

class IDataStore{
    class IFileAccess {};
    
    class IDBAccess {};
    
};

class INetwork{};

class IAudio{};

class ILocation{};

#endif /* defined(__Centri___PlatformSystemInterfaces__) */


#ifndef __Centri___CoreSystemInterfaces__
#define __Centri___CoreSystemInterfaces__

///core services
/// Provides Interfaces to feed and supply information
/// related to game logic, state, entityData 
///
class ICoreServicesDiplay{
    /// I/O Specific to Camera Information
    /// (e.g. coordinates/orientation in world space,
    /// parameters specific to rendering-target features)
    class ICamera{};
    virtual ICamera Camera() = 0;
    
    /// I/O pertaining Entities that are to be rendered on the display (e.g. entity coordinates)
    class IRenderEntities{};
    virtual IRenderEntities RenderEntities() = 0;
    
    /// I/O pertaining to specific display resource (e.g. filepathes of graphics)
    class IResourceDefinitions{};
    virtual IResourceDefinitions ResourceDefinitions() = 0;
    
    /// Register Display Specifications?
    class IDisplayRegistration{};
    virtual IDisplayRegistration DisplayRegistration() = 0;
    
};

class ICoreServiceUserInput{
    class IRotationForce{};
    class ISelection{};
    
};

class ICoreServicesData{};


#endif /* defined(__Centri___CoreSystemInterfaces__) */
