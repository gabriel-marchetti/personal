using LinearAlgebra;

∇f(x1, x2)  = [3*x1^2 + x2; x1 + 2*x2 + 2] 
∇²f(x1, x2) = [6*x1 1;
               1   2]

function direction(x)
    d = -∇f(x[1], x[2]) \ ∇²f(x[1], x[2]);

    return d;
end

x = [0.0; 0.0]

d = transpose(direction(x))