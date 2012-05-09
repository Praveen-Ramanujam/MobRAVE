.. _module-dualmanipulation:

DualManipulation - dualmanipulation
-----------------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-dualmanipulation`

:Interface Author: Achint Aggarwal

Interface for planners using more than one manipulator simultaneously.


DualManipulation Commands
=========================


.. _module-dualmanipulation-grabbody:


GrabBody
~~~~~~~~

Robot calls ::Grab on a body with its current manipulator

~~~~


.. _module-dualmanipulation-help:


help
~~~~

display help commands.

~~~~


.. _module-dualmanipulation-movealljoints:


MoveAllJoints
~~~~~~~~~~~~~

Moves the current active joints to a specified goal destination


~~~~


.. _module-dualmanipulation-movebothhandsstraight:


MoveBothHandsStraight
~~~~~~~~~~~~~~~~~~~~~

Move both the end-effectors in straight lines until collision or IK fails.

~~~~


.. _module-dualmanipulation-releaseall:


ReleaseAll
~~~~~~~~~~

Releases all grabbed bodies (RobotBase::ReleaseAllGrabbed).

~~~~


.. _module-dualmanipulation-setactivemanip:


SetActiveManip
~~~~~~~~~~~~~~

Set the active manipulator

~~~~

