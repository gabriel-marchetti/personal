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
    len = length(x);
    Σ   = 0;
    ∇f  = zeros(len);
    
    for j = 1:len
        aux  = x[1] + x[2]*u[j] - v[j];
        aux1 = atan(aux) + ( π / 2 ) * w[j];
        Σ    = Σ + aux1 * aux1;
        if(flag)
            aux2  = 1 + aux*aux;
            ∇f[1] = ∇f[1] + aux1 / aux2;
            ∇f[2] = ∇f[2] + aux1 * u[j] / aux2;
        end
    end
    ∇f = ∇f .* 2;

    return Σ, ∇f;
end

function gradient_descent(a::Float64, s::Float64, ϵ::Float64,
    M::Int64  , x::Vector{Float64}, fun::Function,
    flag::Bool
    )
    k     = 0; # COUNTER
    f, ∇f = fun(x, true);
    μ     = infty_norm(∇f);
    x_ant = 0;
    ∇f_ant= 0;

    while( (μ >= ϵ) && (k < M) )
        println("$k");
        t_k = 1;
        if( flag == true && k != 0)
            t_k = norm(x - x_ant, 2) / norm(∇f - ∇f_ant, 2);
        end

        w = a * dot(∇f, ∇f);
        while( fun(x - t_k * ∇f, false)[1] > (f - t_k*w) )
            t_k = s * t_k;
        end

        x_ant  = x;
        ∇f_ant = ∇f;
        x      = x - t_k * ∇f;
        f, ∇f  = fun(x, true);
        μ      = infty_norm(∇f);
        k      += 1;
    end
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
    p = gradient_descent(a, s, ϵ, M, x, fun, true);
    println(p);
    println(fun(p, false)[1]);

    colors = ifelse.(w .== 1, "red", "blue");
    x_range = range(-11, 11, length=100);
    #println(p[1]);
    #println(p[2]);
    g(k) = p[1] + k*p[2]; 
    y_range = [g(xp) for xp in x_range];
    per(k) = 4.1949 - k*1.9783;
    y_perf_range = [per(k) for k in x_range];
    #println(y_range);
    p = plot(x_range, y_range, xlim=(-11,11), ylim=(-11,11), label="Função de escolha");
    p = plot!(x_range, y_perf_range, xlim=(-11,11), ylim=(-11,11), label="Função de escolha");
    scatter!(u, v, color=colors, legend=false);
    xlabel!("u");
    ylabel!("v");

end

main()