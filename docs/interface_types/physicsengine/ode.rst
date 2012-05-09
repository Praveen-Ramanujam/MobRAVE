.. _physicsengine-ode:

ode - oderave
-------------

:Type: :ref:`interface-physicsengine`

:Plugin: :ref:`plugin-oderave`

:Interface Author: Rosen Diankov

ODE physics engine

It is possible to set ODE physics engine and its properties inside the <environment> XML tags by typing:

.. code-block:: xml

  <physicsengine type="ode">
    <odeproperties>
      <friction>0.5</friction>
      <gravity>0 0 -9.8</gravity>
      <selfcollision>1</selfcollision>
    </odeproperties>
  </physicsengine>

The possible properties that can be set are: **friction**, **selfcollision**, **gravity**, **contact**, **erp**, **cfm**, **elastic_reduction_parameter**, **constraint_force_mixing**, 




ode Commands
============


.. _physicsengine-ode-help:


help
~~~~

display help commands.

~~~~

