using LinearAlgebra
using Plots; pythonplot()

# Making the infinity norm of a matrix.
function infty_norm(x)
    max = 0;
    for i = 1:length(x)
        if( max < abs(x[i]) )
            max = abs(x[i]);
        end
    end

    return max;
end

function gradient_descent(α::Float64, σ::Float64, ϵ::Float64,
                          M::Int64, x_k::Vector{Float64}, ∇f::Function, f::Function, flag)
    k       = 0;
    g_k     = ∇f(x_k);
    μ       = infty_norm(g_k);
    x_ant   = 0;
    g_k_ant = 0;

    while( (μ >= ϵ) && (k < M) )
        λ_k = 1;

        if ( flag == 1 && k != 0)
            λ_k = norm(x_k - x_ant, 2) / norm(g_k - g_k_ant, 2);
        end
        #Armijo's condition:
        w   = α * dot(g_k, g_k);
        while( f(x_k - λ_k * g_k) > f(x_k) - λ_k*w )
            λ_k = σ * λ_k;
        end

        x_ant   = x_k;
        g_k_ant = g_k;
        x_k     = x_k - λ_k * g_k; 
        g_k     = ∇f(x_k);
        μ       = infty_norm(g_k);
        k       = k + 1;
    end

    return x_k, k;
end

function quad(x::Vector{Float64})
    sum = 0.0;
    for i = 1:length(x)
        sum += i*x[i]^2;
    end

    return sum / 2.0; 
end

function grad_quad(x::Vector{Float64})
    size = length(x);
    grad = zeros(size);

    for (i, val) in enumerate(x)
        grad[i] = i*val;
    end

    return grad;
end

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

function GRAD_ROSENBROK(x::Vector{Float64})
    size = length(x);
    G    = zeros(size);
    size = size / 2;
    limits = convert(Int64, size);
    if (size % 2 == 1)
        println("Invalid Rosenbrok.");
    end

    
    for i = 1:limits
        x_i = x[2*i-1];
        x_p = x[2*i];
        G[2*i] = -20.0*( x_i * x_i - x_p );
        G[2*i - 1] = 40.0*( x_i*x_i - x_p )*x_i + 2.0*( x_i - 1 );    
    end

    return G;
end

α = 10e-4;
σ = 0.5;
ϵ = 1e-5;
M = 1000;
x = [-4.0; 9.0; 2.0; 4.0];

println("-----------QUADRATICA-----------")

x_result_0, iter_0 = gradient_descent(α, σ, ϵ, M, x, grad_quad, quad, 0);

println("Optimal Point: $x_result_0 and Iterations: $iter_0")

x_result_1, iter_1 = gradient_descent(α, σ, ϵ, M, x, grad_quad, quad, 1);

println("Optimal Point: $x_result_1 and Iterations: $iter_1");

println("-----------ROSENBROK-----------")

x_result_0_Rosen, iter_0_Rosen = gradient_descent(α, σ, ϵ, M, x, GRAD_ROSENBROK, ROSENBROK, 0);

println("Optimal Point: $x_result_0_Rosen and Iterations: $iter_0_Rosen");

x_result_1_Rosen, iter_1_Rosen = gradient_descent(α, σ, ϵ, M, x, GRAD_ROSENBROK, ROSENBROK, 1);

println("Optimal Point: $x_result_1_Rosen and Iterations: $iter_1_Rosen");

f(x, y) = ( 3*x + y*y ) * abs( sin(x) + cos(y) )

x = range(0, 5, length = 100);
y = range(0, 3, length = 100);
z = @. f(x', y)

contour(x, y, z);

R = hcat(x, y)
x_range = range(start=-2, stop=2, length=100);
y_range = range(start=-2, stop=2, length=100);

# Criar matrizes de combinação de x com y.

dimX = length(x_range);
dimY = length(y_range);
points_matrix = Matrix{Point}(undef, dimX, dimY);

struct Point
    x::Float64;
    y::Float64;
end

for i = 1:dimX
    for j = 1:dimY
        points_matrix[i, j] = Point(convert(Float64, x[i]), convert(Float64, y[i]))
    end
end

z_range = 
