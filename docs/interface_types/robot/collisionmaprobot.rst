.. _robot-collisionmaprobot:

CollisionMapRobot - baserobots
------------------------------

:Type: :ref:`interface-robot`

:Plugin: :ref:`plugin-baserobots`

:Interface Author: Rosen Diankov

Allows user to specify regions of the robot configuration space that are in self-collision via lookup tables. This is most commonly used when two or more joints are coupled and their joint limits cannot be specified by simple min/max limits. A CollisionMap robot allows the user to specify self-collision regions indexed by the values of two joints. The map will be 1 if the values are allowed or 0. If the robot gets into a 0 region, it will get into self-collision.

This is done by first creating a robot of type 'CollisionMapRobot' and using the **<collisionmap>** XML tag. Inside the **<collisionmap>** tag, multiple **<pair>** tags can be specified for coupled joints. For example, to specify a 181x181 2D map for joints J0, J1, J2, J3 where J0,J1 are paired and J2,J3 are paired, do: 

.. code-block:: xml

  <robot type="CollisionMapRobot">
    ...
    <collisionmap>
      <pair dims="181 181" min="-1.5708 -1.5708" max="1.5708 1.5708" joints="J0 J1">
        <!-- 181x181 values of 0s and 1s -->
      </pair>
      <pair dims="91 131" min="-1 -2" max="1 2" joints="J2 J3">
        <!-- 91x131 values of 0s and 1s -->
      </pair>
    </collisionmap>
  </robot>

The first pair specifies a map where both joints J0 and J1 have range [-1.5708,1,5708]. This is usually the joint limits specified in the **<joint>** definition.

In order to index into the two maps defined above, the following operation is performed::

  pair_J0xJ1[ 180*(J0+1.57)/(1.57+1.57) ][ 180*(J1+1.57)/(1.57+1.57) ]

For joints J2xJ3, the index operation is::

  pair_J2xJ3[ 90*(J2+1)/(1+1) ][ 130*(J3+2)/(2+2) ]




CollisionMapRobot Commands
==========================


.. _robot-collisionmaprobot-help:


help
~~~~

display help commands.

~~~~

