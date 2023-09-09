using LinearAlgebra
using Plots; pythonplot()

function SPHERE_FUNCTION(x::Vector{Float64})
    dim     = length(x);
    info    = 0;
    for i = 1:dim
        info += x[i]^2;
    end

    return info;
end

x_range     = range(-5.12, 5.12, length=1000);
y_range     = range(-5.12, 5.12, length=1000);

z_values    = [SPHERE_FUNCTION([x, y]) for x in x_range, y in y_range];

contour(x_range, y_range, z_values, levels=20, color=:turbo)