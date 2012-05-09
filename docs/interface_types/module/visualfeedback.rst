.. _module-visualfeedback:

VisualFeedback - rmanipulation
------------------------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-rmanipulation`

:Interface Author: Rosen Diankov

.. image:: ../../../images/interface_visualfeedback.jpg
  :width: 500

Adds grasp planning taking into account camera visibility constraints. The relevant paper is:

- Rosen Diankov, Takeo Kanade, James Kuffner. Integrating Grasp Planning and Visual Feedback for Reliable Manipulation, IEEE-RAS Intl. Conf. on Humanoid Robots, December 2009.

Visibility computation checks occlusion with other objects using ray sampling in the image space:

.. image:: ../../../images/interface_visualfeedback_occlusions.jpg
  :height: 200



VisualFeedback Commands
=======================


.. _module-visualfeedback-computevisibility:


ComputeVisibility
~~~~~~~~~~~~~~~~~

Computes the visibility of the current robot configuration

~~~~


.. _module-visualfeedback-computevisibleconfiguration:


ComputeVisibleConfiguration
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gives a camera transformation, computes the visibility of the object and returns the robot configuration that takes the camera to its specified position, otherwise returns false

~~~~


.. _module-visualfeedback-help:


help
~~~~

display help commands.

~~~~


.. _module-visualfeedback-movetoobservetarget:


MoveToObserveTarget
~~~~~~~~~~~~~~~~~~~

Approaches a target object while choosing a goal such that the robot's camera sensor sees the object 

~~~~


.. _module-visualfeedback-processvisibilityextents:


ProcessVisibilityExtents
~~~~~~~~~~~~~~~~~~~~~~~~

Processes the visibility extents of the target and initializes the camera transforms.

:param sphere: Sets the transforms along a sphere density and the distances
:param conedirangle: Prunes the currently set transforms along a cone centered at the local target center and directed towards conedirangle with a half-angle of ``|conedirangle|``. Can specify multiple cones for an OR effect.

~~~~


.. _module-visualfeedback-samplevisibilitygoal:


SampleVisibilityGoal
~~~~~~~~~~~~~~~~~~~~

Samples a goal with the current manipulator maintaining camera visibility constraints

~~~~


.. _module-visualfeedback-setcameraandtarget:


SetCameraAndTarget
~~~~~~~~~~~~~~~~~~

Sets the camera index from the robot and its convex hull

~~~~


.. _module-visualfeedback-setcameratransforms:


SetCameraTransforms
~~~~~~~~~~~~~~~~~~~

Sets new camera transformations. Can optionally choose a minimum distance from all planes of the camera convex hull (includes gripper mask)

~~~~


.. _module-visualfeedback-setparameter:


SetParameter
~~~~~~~~~~~~

Sets internal parameters of visibility computation

~~~~


.. _module-visualfeedback-visualfeedbackgrasping:


VisualFeedbackGrasping
~~~~~~~~~~~~~~~~~~~~~~

Stochastic greedy grasp planner considering visibility

~~~~

