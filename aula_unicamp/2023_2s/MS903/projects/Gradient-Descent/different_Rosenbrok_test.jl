using LinearAlgebra
using Plots; pythonplot()

function ROSENBROK(x::Vector{Float64})
    f       = 0;
    size    = length(x);
    size    = size / 2;
    limits  = convert(Int64, size);
    for i = 1:limits
        f += 10*(x[2*i] - x[2*i-1]^2)^2 + ( x[2*i-1] - 1 )^2;
    end

    return f;
end

x_range = range(-4, 4, length=1000);
y_range = range(-8, 8, length=1000);

z_values = [ROSENBROK([x, y]) for x in x_range, y in y_range];

contour(x_range, y_range, z_values, levels=20, color=:turbo)