using LinearAlgebra;
using Plots;
using Random;
global u, v, w, N;

file_path = "data_project3.txt";
u         = Vector{Float64}();
v         = Vector{Float64}();
w         = Vector{Float64}();

function load_info()
    file = open(file_path);
    for line in eachline(file)
        row     = parse.(Float64, split(line));
        push!(u, row[1]);
        push!(v, row[2]);
        push!(w, row[3]);
    end
end
load_info();

function infty_norm(x)
    max = 0;
    for i = 1:length(x)
        if( max < abs(x[i]) )
            max = abs(x[i]);
        end
    end

    return max;
end

function my_function_reduzida(x)
    N = length(u)                             ;
    f = 0                                     ;
    g = [0.0; 0.0]                            ;
    index = floor( rand()*N ) + 1             ;
    index = convert(Int64, index)             ;
    aux1  = x[1] + x[2] * u[index] - v[index] ;
    aux2  = atan(aux1) + 0.5 * π * w[index]   ;
    f     = ( aux2 * aux2 )                   ;
    aux3  = aux2 / ( 1 + aux1 * aux1 )        ;
    g[1]  = aux3                              ;
    g[2]  = aux3 * u[index]                   ;

    indexes[index] = indexes[index] + 1;
    println(index);
    return f, g
end

function gradient_descent_stochastic(ϵ::Float64, M::Int64, x::Vector{Float64}, t::Float64)
    k      = 0; # COUNTER
    f, ∇f  = my_function_reduzida(x);
    μ      = infty_norm(∇f);
    x_ant  = 0;
    ∇f_ant = 0;

    while( (μ >= ϵ) && (k < M) )
        x_ant  = x;
        ∇f_ant = ∇f;
        x      = x - t * ∇f;
        f, ∇f  = my_function_reduzida(x);
        μ      = infty_norm(∇f);
        k      += 1;
    end

    println("Interations: $k");
    return x;
end

global indexes = zeros(length(u));
a = 10e-4;
M = 1000 ;
x = [-5.0; -5.0];
t = 1.0;
x = gradient_descent_stochastic(ϵ, M, x, t);
indexes = convert(Vector{Int64}, indexes);

function teste(x::Vector{Float64})
    g(__x__) = x[1] + __x__*x[2]; 
    x_range = range(-11, 11, length = 100);
    N       = length(u);
    y_range = [g(dumb) for dumb in x_range];
    p       = plot(x_range, y_range, xlims=(-11, 11), ylims=(-11, 11), label=false)
    
    colors  = ifelse.(w .== 1, "red", "blue");
    p       = scatter!(u, v, color=colors, label=false);
    missed   = 0;

    # Check if the prediction is correct!
    for i = 1:N
        is_under = -1.0;
        #Check if point is under the curve.
        val      = x[1] + x[2]*u[i];
        if( v[i] > val )
            is_under = 1.0;
        end


        if(is_under != w[i])
            # Defining color pallet
            if( w[i] == 1.0 ) 
                reversed_color = "blue";
            else
                reversed_color = "red" ;
            end
        
            # Scattering
            scatter!( [u[i]], [v[i]], color=reversed_color,
                       markershape=:cross, markersize=10, label=false
            );
            # Counting missed points
            missed += 1;
        end

        error = missed / N;
        error *= 100      ;

        error = round(error, digits = 3);
        title!("Missed points: $error%   Total of Points:$N    Missed:$missed",
               titlefont = font(12,"Computer Modern")
        );
    end
    #####################################

    return p;
end

teste(x)