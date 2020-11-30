# curaga
The software side of a Arduino powered UV curing device


This is very much a work in progress

**Please do not set yourself on fire**


## What I'm Trying to Accomplish

I've been trying to lay down epoxy resins to be paper thin as an alternative
to purchasing costly sheets of acrylic which then need to be cut down to size.

The problem that I've been running into is intensive bubbling and warping of 
the liquid epoxy during the polymerization process.

I believe that this is a result of two variables: The intensity of the light,
and air dissolved in the liquid resin.

My goal is to remove, or at a minimum control from those two variables.

## How are you doing that?!

By using a simple microcontroller!

## Gotchas

Voltage! The LEDs that I'm using can either be 3.3V or 12V. 

### Inputs

Potentiometer 1: Adjust the intensity of the lights

Potentiometer 2: Rotational speed of the motor

Button *n*: Trigger a preprogrammed set of actions

#### Outputs
Relay 1: Toggle vacuum

MOSFET 1: Control intensity of the lights via PWM

SDA/SCL: OLED Screen


## Tasks

- [x] Potentiometers

- [ ] Relay


## Wishlist

[] 
