.. _controller-idealcontroller:

IdealController - basecontrollers
---------------------------------

:Type: :ref:`interface-controller`

:Plugin: :ref:`plugin-basecontrollers`

:Interface Author: Rosen Diankov

Ideal controller used for planning and non-physics simulations. Forces exact robot positions.

If ef ControllerBase::SetPath is called and the trajectory finishes, then the controller will continue to set the trajectory's final joint values and transformation until one of three things happens:

1. ControllerBase::SetPath is called.

2. ControllerBase::SetDesired is called.

3. ControllerBase::Reset is called resetting everything

If SetDesired is called, only joint values will be set at every timestep leaving the transformation alone.



IdealController Commands
========================


.. _controller-idealcontroller-help:


help
~~~~

display help commands.

~~~~


.. _controller-idealcontroller-pause:


Pause
~~~~~

pauses the controller from reacting to commands 

~~~~


.. _controller-idealcontroller-setcheckcollisions:


SetCheckCollisions
~~~~~~~~~~~~~~~~~~

If set, will check if the robot gets into a collision during movement

~~~~


.. _controller-idealcontroller-setthrowexceptions:


SetThrowExceptions
~~~~~~~~~~~~~~~~~~

If set, will throw exceptions instead of print warnings

~~~~

