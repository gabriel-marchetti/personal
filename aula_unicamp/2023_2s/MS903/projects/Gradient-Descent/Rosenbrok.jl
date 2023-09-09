using LinearAlgebra
using Plots; pythonplot()

function ROSENBROK(x::Vector{Float64})
    dim   = length(x);
    value = 0;

    for i = 1:dim-1
        x_i = x[i];
        x_i_next = x[i+1];
        value += ( 100*(x_i_next - x_i^2)^2 + (1 - x_i)^2 );
    end

    return value;
end

x_range = range(-4, 4, length=1000);
y_range = range(-8, 8, length=1000);

z_values = [ROSENBROK([x, y]) for x in x_range, y in y_range];

contour(x_range, y_range, z_values, levels=20, color=:turbo)