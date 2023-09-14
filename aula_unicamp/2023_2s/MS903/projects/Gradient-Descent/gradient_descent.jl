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

function gradient_descent(a::Float64, s::Float64, ϵ::Float64,
                          M::Int64, x_k::Vector{Float64}, ∇f::Function, f::Function, flag)
    k       = 0;
    g_k     = ∇f(x_k);
    μ       = infty_norm(g_k);
    f_val   = f(x_k);
    x_ant   = 0;
    g_k_ant = 0;

    while( (μ >= ϵ) && (k < M) )
        λ_k = 1;

        if ( flag == 1 && k != 0)
            λ_k = norm(x_k - x_ant, 2) / norm(g_k - g_k_ant, 2);
        end
        #Armijo's condition:
        w   = a * dot(g_k, g_k);

        while( f(x_k - λ_k * g_k) > f_val - λ_k*w )
            λ_k = s * λ_k;
        end

        x_ant   = x_k;
        g_k_ant = g_k;
        x_k     = x_k - λ_k * g_k; 
        g_k     = ∇f(x_k);
        μ       = infty_norm(g_k);
        f_val   = f(x_k);
        #println(f_val);
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
        x_p = x[2*i];
        x_i = x[2*i - 1];
        f += 10*(x_p - x_i * x_i)*(x_p - x_i * x_i) + ( x_i - 1 )*( x_i - 1 );
    end

    return f;
end

function GRAD_ROSENBROK(x::Vector{Float64})
    size = length(x);
    G    = zeros(size);
    size = size / 2;
    limits = convert(Int64, size);

    
    for i = 1:limits
        x_i = x[2*i-1];
        x_p = x[2*i];
        G[2*i] = 20.0*( x_p - x_i * x_i  );
        G[2*i - 1] = 40.0*( x_i*x_i - x_p )*x_i + 2.0*( x_i - 1 );    
    end

    return G;
end

a = 10e-4;
s = 0.5;
ϵ = 1e-5;
M = 1000;
x = [-1.0; 3.0];

println("-----------QUADRATICA-----------")

x_result_0, iter_0 = gradient_descent(a, s, ϵ, M, x, grad_quad, quad, 0);

println("Optimal Point: $x_result_0 and Iterations: $iter_0")

x_result_1, iter_1 = gradient_descent(a, s, ϵ, M, x, grad_quad, quad, 1);

println("Optimal Point: $x_result_1 and Iterations: $iter_1");

println("-----------ROSENBROK-----------")

x_result_0_Rosen, iter_0_Rosen = gradient_descent(a, s, ϵ, M, x, GRAD_ROSENBROK, ROSENBROK, 0);

println("Optimal Point: $x_result_0_Rosen and Iterations: $iter_0_Rosen");

x_result_1_Rosen, iter_1_Rosen = gradient_descent(a, s, ϵ, M, x, GRAD_ROSENBROK, ROSENBROK, 1);

println("Optimal Point: $x_result_1_Rosen and Iterations: $iter_1_Rosen");

f(x, y) = ( 3*x + y*y ) * abs( sin(x) + cos(y) );

x = range(-5, 5, length = 100);
y = range(-5, 5, length = 100);
z = @. f(x', y);

contour(x, y, z)

# R = hcat(x, y)
x_range = range(start=-10, stop=10, length=1000);
y_range = range(start=-10, stop=10, length=1000);

# Criar matrizes de combinação de x com y.
dimX = length(x_range);
dimY = length(y_range);
# Useless code... Just for reference.
# points_matrix = Matrix{Point}(undef, dimX, dimY);
# values = Matrix{Float64}(undef, dimX, dimY);

# struct Point
#    x::Float64;
#    y::Float64;
# end

# for i = 1:dimX
#    for j = 1:dimY
#        x = [convert(Float64, x_range[i]), convert(Float64, y_range[i])];
#        # display(x);
#        # display(length(x));
#        values[i, j] = ROSENBROK(x);
#    end
# end

z_values = [ROSENBROK([x, y]) for x in y_range, y in x_range]; 
contour(x_range, y_range, z_values, levels=20)

#x_points = [x_result_0_Rosen[1], x_result_1_Rosen[1]]
#y_points = [x_result_0_Rosen[2], x_result_1_Rosen[2]]

#scatter!(x_points, y_points, label="Pontos de mínimo", legend=false)

ponto1 = [x_result_0_Rosen[1], x_result_0_Rosen[2]];
ponto2 = [x_result_1_Rosen[1], x_result_1_Rosen[2]];
scatter!([ponto1[1]], [ponto1[2]], label="Ponto de minimo sem passo", legend=true)
scatter!([ponto2[1]], [ponto2[2]], label="Ponto de minimo com passo", legend=true)

function generate_graphics(f::Function)
    x_range = range(start=-10, stop=10, length=1000);
    y_range = range(start=-6, stop=6, length=1000);
    z_values = [f([x, y]) for x in y_range, y in x_range]; 

    contour(x_range, y_range, z_values, levels=50)
end

generate_graphics(ROSENBROK)

function my_max(v::Vector{Float64})
    max = v[1];
    for i = 1:length(v)
        if( v[i] > max)
            max = v[i];
        end
    end

    return max;
end

function gradient_descent_p_infos(a::Float64, s::Float64, ϵ::Float64,
    M::Int64, x_k::Vector{Float64}, ∇f::Function, f::Function, p::Int64, flag)
    k       = 0;
    g_k     = ∇f(x_k);
    μ       = infty_norm(g_k);
    x_ant   = 0;
    g_k_ant = 0;
    # Create p-array:
    array       = fill(f(x_k), p);
    array_pos   = 1;

    while( (μ >= ϵ) && (k < M) )
        λ_k = 1;

        if ( flag == 1 && k != 0)
            λ_k = norm(x_k - x_ant, 2) / norm(g_k - g_k_ant, 2);
        end
        #Armijo's condition:
        w   = a * dot(g_k, g_k);
        while( f(x_k - λ_k * g_k) > my_max(array) - λ_k*w )
            λ_k = s * λ_k;
        end

        # Static-Array Implementation.
        array_pos += 1;
        array_pos = array_pos % p;
        # Problem with julia indexing, bc of mod operation. Can return 0, but index starts at 1.
        if (array_pos == 0)
            array_pos = 1;
        end
        array[array_pos] = f(x_k);

        x_ant   = x_k;
        g_k_ant = g_k;
        x_k     = x_k - λ_k * g_k; 
        g_k     = ∇f(x_k);
        μ       = infty_norm(g_k);
        k       = k + 1;
    end

    return x_k, k;
end

x = [-1.0, 3.0];
println("Modificado: ");
x_modificado, iter_modificado = gradient_descent_p_infos(a, s, ϵ, M, x, GRAD_ROSENBROK, ROSENBROK, 2, 1);
println("Optimal Point: $x_modificado and Iterations: $iter_modificado");