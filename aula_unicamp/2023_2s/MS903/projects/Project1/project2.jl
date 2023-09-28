using LinearAlgebra;
using Plots;
global u, v, w, N;

file_path = "data_project2.txt";
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

function infty_norm(x)
    max = 0;
    for i = 1:length(x)
        if( max < abs(x[i]) )
            max = abs(x[i]);
        end
    end

    return max;
end

function fun(x::Vector{Float64}, flag::Bool)
    Σ   = 0;
    ∇f  = zeros(length(x));
    global u
    global v
    global w
    u = convert(Vector{Float64}, u)
    v = convert(Vector{Float64}, v)
    w = convert(Vector{Float64}, w)
    
    for j = 1:length(u)
        aux1 = x[1] + x[2]*u[j] - v[j];
        aux2 = atan(aux1) + ( π / 2 ) * w[j];
        Σ    = Σ + aux2 * aux2;
        if(flag)
            aux3  = 1 + aux1*aux1;
            ∇f[1] = ∇f[1] + (aux2 / aux3);
            ∇f[2] = ∇f[2] + (aux2 * u[j] / aux3);
        end
    end
    ∇f = ∇f .* 2;

    return Σ, ∇f;
end

function my_function(x)
    N = length(u)
    f = 0
    g = [0.0, 0.0]
    aux1 = x[1] .+ x[2] .* u .- v
    aux2 = atan.(aux1) .+ 0.5 * π .* w
    f = 0.5 * sum(aux2 .* aux2) / N
    aux3 = aux2 ./ (1 .+ aux1 .* aux1)
    g[1] = sum(aux3) / N
    g[2] = sum(aux3 .* u) / N
    return f, g
end


function gradient_descent(a::Float64, s::Float64, ϵ::Float64,
    M::Int64  , x::Vector{Float64}, fun::Function,
    flag::Bool
    )
    k     = 0; # COUNTER
    f, ∇f = fun(x);
    μ     = infty_norm(∇f);
    x_ant = 0;
    ∇f_ant= 0;

    while( (μ >= ϵ) && (k < M) )
        #println("$k");
        t_k = 1;
        if( flag == true && k != 0)
            t_k = norm(x - x_ant, 2) / norm(∇f - ∇f_ant, 2);
        end

        armijo = a * dot(∇f, ∇f);
        while( fun(x - t_k * ∇f)[1] > (f - t_k*armijo) )
            t_k = s * t_k;
        end

        x_ant  = x;
        ∇f_ant = ∇f;
        x      = x - t_k * ∇f;
        f, ∇f  = my_function(x);
        μ      = infty_norm(∇f);
        k      += 1;
    end

    #println("$k");
    return x;
end

function main()
    load_info();
    # PARAMETERS
    a = 10e-4;
    s = 0.5  ;
    ϵ = 1e-5 ;
    M = 1000 ;
    # INITIAL GUESS
    x = [0.0; 0.0];
    p = gradient_descent(a, s, ϵ, M, x, my_function, true);
    println(p);
    println(fun(p, true)[1]);

    colors = ifelse.(w .== 1, "red", "blue");
    x_range = range(-11, 11, length=100);
    #println(p[1]);
    #println(p[2]);
    g(k) = p[1] + k*p[2]; 
    y_range = [g(xp) for xp in x_range];
    #per(k) = 4.1949 - k*1.9783;
    #y_perf_range = [per(k) for k in x_range];
    #println(y_range);
    p = plot(x_range, y_range, xlim=(-11,11), ylim=(-11,11), label="Função de escolha");
    #p = plot!(x_range, y_perf_range, xlim=(-11,11), ylim=(-11,11), label="Função de escolha");
    scatter!(u, v, color=colors, legend=false);
    xlabel!("u");
    ylabel!("v");

end
main()

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
        title!("Missed points: $error%   Total of Points:$N    Missed:$missed",
               titlefont = font(12,"Computer Modern")
        );
    end
    #####################################

    return p;
end

teste(x)

a = 10e-4;
s = 0.5  ;
ϵ = 1e-5 ;
M = 1000 ;
x = [0.0; 0.0];
x = gradient_descent(a, s, ϵ, M, x, my_function, true);

main()