/*
Contents:
	- Some interfaces (in order):
		- Entity
		- EntityAction
		- Ship
		- ShipController
		- ShipAttribute
		- ShipStatus
		- ShipUpgrade
		- GraphicsObject
		- PhysicsMotionState
		- PhysicsObject
*/

// This represents an object (player, minion, bullet, effect sprite, etc) in the world.  It provides both the graphical and physical
// representations of the object.
class Entity
{
public:
	virtual PhysicsMotionState &GetPhysicsMotionState() const = 0; // Implementations should probably return the motion state found inside the physics object.

	virtual GraphicsObject &GetGraphicalRepresentation() const = 0;
	virtual PhysicsObject &GetPhysicalRepresentation() const = 0;

	virtual void ApplyAction(EntityAction &) = 0; // This should be used instead of calling EntityAction::ApplyTo directly so that an entity has an opportunity to apply some entity-specific modifications to the action if need be.
};

// This provides a controlled, general way to move an entity.  The benefit of abstracting this functionality into a class could be
// the ability to easily increase all movement speeds by 20%, for example.  Or to provide movements that are or are not buffed/debuffed
// by status effects.
class EntityAction
{
public:
	virtual void ApplyTo(Entity &) const = 0;
};

// This holds the important data and attributes of a ship and provides its behavior.
class Ship
{
public:
	virtual Entity &GetEntity() const = 0;

	virtual ShipStatus &GetShipStatus() const = 0;
	virtual std::vector<ShipUpgrade &> GetShipUpgrades() = 0;

	virtual ShipController &GetShipController() const = 0;

	virtual void Update() = 0; // Should probably mess with status effects, update the entity with the controller, etc.
};

// InputDevices will be connected to a kind of input server that will send messages to listening Controllers like these.
// Controllers are the things that put input into motion in some form or another.  For instance, there should probably be a
// menu controller that interprets input to change the menu selection.
class ShipController : public Controller
{
public:
	virtual void UpdateShipEntity(Entity &, ShipStatus const &) const = 0;
};

// Identifies a type of ship attribute.  Behaves like std::string in standard containers.
struct ShipAttribute
{
	ShipAttribute(std::string Name, unsigned int UID) : Name(Name) { }
	std::string GetName() const { return Name; }
	std::string GetOwner() const { return Owner; }

	bool operator<(ShipAttribute const &b) const
	{
		if (Name == b.GetName())
			return Owner < b.GetOwner();
		return Name < b.GetName();
	}
	bool operator==(ShipAttribute const &b) const { return (Name == b.GetName() && Owner == b.GetOwner()); }

private:
	std::string Name;
	std::string Owner;
};

// This holds arbitrary ship status attributes like movement speed, attack speed/damage, etc.  Upgrades should never modify core attributes
// and instead add new attributes like "Movement Speed" with the upgrade's name in the Owner field.  They can be aggregated later.
class ShipStatus
{
public:
	virtual float GetScalarAttribute(ShipAttribute const &) const = 0;
	// ... probably some other types like GetVectorAttribute, maybe GetStringAttribute.

	virtual bool SetScalarAttribute(ShipAttribute const &, float) = 0;
	// ...

	virtual void CalculateCoreAttributes() = 0;
};

// General upgrade interface.  The tech tree hierarchy will be implied by the child members.
class ShipUpgrade
{
public:
	virtual std::vector<ShipUpgrade &> GetChildren() const = 0;

	virtual std::vector<ShipAttribute> GetAttributes() const = 0;

	virtual unsigned int GetCost() const = 0;
};

// Provides a Renderer class with all conceivable information it might need to properly render this object.  This'll probably get filled
// out when we figure out the capabilities of the renderer we're going to implement.  Ultimately though, this will be renderer agnostic.
// Someone modifying our code should find enough information to render these objects using photon mapping or something equally arcane if
// they so choose. :P
class GraphicsObject;

// This stuff will fall into place when the physics engine is written.  I've written some physics code in the past and had a good bit
// of success modeling it after Bullet.  They know their stuff.
class PhysicsMotionState;
class PhysicsObject;
