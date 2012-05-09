"""
If the arbitrary constant class from issue 1336 is ever implemented, this
should serve as a set of test cases.
"""

from sympy import sin, exp, Function, Symbol, S, Pow, Eq, I, sinh, cosh, acos,\
cos, log, Rational, sqrt, Integral
from sympy.solvers.ode import constantsimp, ode_renumber
from sympy.utilities.pytest import XFAIL


x = Symbol('x')
y = Symbol('y')
z = Symbol('z')
C1 = Symbol('C1')
C2 = Symbol('C2')
C3 = Symbol('C3')
f = Function('f')

def test_constant_mul():
    # We want C1 (Constant) below to absorb the y's, but not the x's
    assert ode_renumber(constantsimp(y*C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(x*C1, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(C1*y, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1*x, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(2*C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1*2, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(y*C1*x, x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(x*y*C1, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(y*x*C1, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(C1*y*(y + 1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(y*C1*(y + 1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(x*(y*C1), x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(x*(C1*y), x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(C1*(x*y), x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp((x*y)*C1, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp((y*x)*C1, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(y*(y + 1)*C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1*x*y, x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(x*C1*y, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp((C1*x)*y, x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(y*(x*C1), x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp((x*C1)*y, x, 1), 'C', 1, 1) == x*C1
    assert ode_renumber(constantsimp(C1*x*y*x*y*2, x, 1), 'C', 1, 1) == C1*x**2
    assert ode_renumber(constantsimp(C1*x*y*z, x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(C1*x*y**2*sin(z), x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(C1*C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1*C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C2*C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C1*C1*C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C1*x*2**x, x, 1), 'C', 1, 1) == C1*x*2**x

def test_constant_add():
    assert ode_renumber(constantsimp(C1 + C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1 + 2, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(2 + C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1 + y, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1 + x, x, 1), 'C', 1, 1) == C1 + x
    assert ode_renumber(constantsimp(C1 + x + y + x*y + 2, x, 1), 'C', 1, 1) == \
        C1 + x + x*y
    assert ode_renumber(constantsimp(C1 + x + 2**x + y + 2, x, 1), 'C', 1, 1) == \
        C1 + x + 2**x
    assert ode_renumber(constantsimp(C1 + C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1 + C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C2 + C1, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C1 + C2 + C1, x, 2), 'C', 1, 2) == C1

def test_constant_power_as_base():
    assert ode_renumber(constantsimp(C1**C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(Pow(C1,C1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1**C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1**C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C2**C1, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C2**C2, x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(C1**y, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1**x, x, 1), 'C', 1, 1) == C1**x
    assert ode_renumber(constantsimp(C1**2, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(C1**(x*y), x, 1), 'C', 1, 1) == C1**(x*y)

def test_constant_power_as_exp():
    assert ode_renumber(constantsimp(x**C1, x, 1), 'C', 1, 1) == x**C1
    assert ode_renumber(constantsimp(y**C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(x**y**C1, x, 1), 'C', 1, 1) == x**C1
    assert ode_renumber(constantsimp((x**y)**C1, x, 1), 'C', 1, 1) == (x**y)**C1
    assert ode_renumber(constantsimp(x**(y**C1), x, 1), 'C', 1, 1) == x**C1
    assert ode_renumber(constantsimp(x**C1**y, x, 1), 'C', 1, 1) == x**C1
    assert ode_renumber(constantsimp(x**(C1**y), x, 1), 'C', 1, 1) == x**C1
    assert ode_renumber(constantsimp((x**C1)**y, x, 1), 'C', 1, 1) == (x**C1)**y
    assert ode_renumber(constantsimp(2**C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(S(2)**C1, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(exp(C1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(exp(C1+x), x, 1), 'C', 1, 1) == exp(C1+x)
    assert ode_renumber(constantsimp(Pow(2, C1), x, 1), 'C', 1, 1) == C1

def test_constant_function():
    assert ode_renumber(constantsimp(sin(C1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(f(C1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(f(C1, C1), x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(f(C1, C2), x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(f(C2, C1), x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(f(C2, C2), x, 2), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(f(C1, x), x, 1), 'C', 1, 2) == f(C1, x)
    assert ode_renumber(constantsimp(f(C1, y), x, 1), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(f(y, C1), x, 1), 'C', 1, 2) == C1
    assert ode_renumber(constantsimp(f(C1, y, C2), x, 2), 'C', 1, 2) == C1

@XFAIL
def test_constant_function_multiple():
    # The rules to not renumber in this case would be too complicated, and
    # dsolve is not likely to ever encounter anything remotely like this.
    assert ode_renumber(constantsimp(f(C1, C1, x), x, 1), 'C', 1, 1) == f(C1, C1, x)

def test_constant_multiple():
    assert ode_renumber(constantsimp(C1*2 + 2, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(x*2/C1, x, 1), 'C', 1, 1) == C1*x
    assert ode_renumber(constantsimp(C1**2*2 + 2, x, 1), 'C', 1, 1) == C1
    assert ode_renumber(constantsimp(sin(2*C1) + x + sqrt(2), x, 1), 'C', 1, 1) == C1 + x
    assert ode_renumber(constantsimp(2*C1 + C2, x, 2), 'C', 1, 2) == C1

def test_ode_solutions():
    # only a few examples here, the rest will be tested in the actual dsolve tests
    assert ode_renumber(constantsimp(C1*exp(2*x)+exp(x)*(C2+C3), x, 3), 'C', 1, 3) == \
        ode_renumber(C1*exp(x)+C2*exp(2*x), 'C', 1, 2)
    assert ode_renumber(constantsimp(Eq(f(x),I*C1*sinh(x/3) + C2*cosh(x/3)), x, 2),
        'C', 1, 2) == ode_renumber(Eq(f(x), C1*sinh(x/3) + C2*cosh(x/3)), 'C', 1, 2)
    assert ode_renumber(constantsimp(Eq(f(x),acos((-C1)/cos(x))), x, 1), 'C', 1, 1) == \
        Eq(f(x),acos(C1/cos(x)))
    assert ode_renumber(constantsimp(Eq(log(f(x)/C1) + 2*exp(x/f(x)), 0), x, 1),
        'C', 1, 1) ==  Eq(log(C1*f(x)) + 2*exp(x/f(x)), 0)
    assert ode_renumber(constantsimp(Eq(log(x*2**Rational(1,2)*(1/x)**Rational(1,2)*f(x)\
        **Rational(1,2)/C1) + x**2/(2*f(x)**2), 0), x, 1), 'C', 1, 1) == \
        Eq(log(C1*x*(1/x)**Rational(1,2)*f(x)**Rational(1,2)) + x**2/(2*f(x)**2), 0)
    assert ode_renumber(constantsimp(Eq(-exp(-f(x)/x)*sin(f(x)/x)/2 + log(x/C1) - \
        cos(f(x)/x)*exp(-f(x)/x)/2, 0), x, 1), 'C', 1, 1) == \
        Eq(-exp(-f(x)/x)*sin(f(x)/x)/2 + log(C1*x) - cos(f(x)/x)*exp(-f(x)/x)/2, 0)
    u2 = Symbol('u2')
    _a = Symbol('_a')
    assert ode_renumber(constantsimp(Eq(-Integral(-1/((1 - u2**2)**Rational(1,2)*u2), \
        (u2, _a, x/f(x))) + log(f(x)/C1), 0), x, 1), 'C', 1, 1) == \
        Eq(-Integral(-1/(u2*(1 - u2**2)**Rational(1,2)), (u2, _a, x/f(x))) + \
        log(C1*f(x)), 0)
    assert map(lambda i: ode_renumber(constantsimp(i, x, 1), 'C', 1, 1),
        [Eq(f(x), (-C1*x + x**2)**Rational(1,2)), Eq(f(x), -(-C1*x +
        x**2)**Rational(1,2))]) == [Eq(f(x), (C1*x + x**2)**Rational(1,2)),
        Eq(f(x), -(C1*x + x**2)**Rational(1,2))]
