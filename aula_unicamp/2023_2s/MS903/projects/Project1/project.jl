using LinearAlgebra;
global data, u, v, N;

file_path = "data.txt";
data      = Vector{Vector{Float64}}();
u         = Vector{Float64}();
v         = Vector{Float64}();
N         = 0;

function fun(x::Vector{Float64}, flag::Bool)
    f = 0;
    ∇f = zeros(length(x));
    if(flag)
        for j = 1:N
            Aux1 = exp(x[3]*u[j]);
            Aux2 = x[2] * Aux1;
            Aux3 = x[1] + Aux2 - v[j];
            f    = f + Aux3 * Aux3;
            ∇f[1] += Aux3;
            ∇f[2] += Aux3*Aux1;
            ∇f[3] += Aux3*Aux2*u[j];
        end
        f = f / (2*N);
        ∇f= ∇f ./ N;
    else
        for j = 1:N
            Aux = x[1] + x[2] * exp(x[3]*u[j]) - v[j];
            f   = f + Aux*Aux;
        end
        f = f / (2*N);
        ∇f .= [0.0; 0.0; 0.0];
    end

    return f, ∇f;
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
        t_k = 1;
        if( flag == true && k != 0)
            t_k = norm(x - x_ant, 2) / norm(∇f - ∇f_ant, 2);
        end

        w = a * dot(∇f, ∇f);
        while( fun(x - t_k * ∇f, false)[1] > (f - t_k*w) )
            t_k = s * t_k;
        end

        x_ant = x;
        ∇f_ant= ∇f;
        f, ∇f = fun(x - t_k * ∇f, true);
        μ     = infty_norm(∇f);
        k     += 1;
    end

    return x;
end

function main(filepath)
    file = open(filepath, "r");
    for line in eachline(file)
        row = parse.(Float64, split(line));
        push!(data, row);
        push!(u, row[1]);
        push!(v, row[2]);
        global N += 1;
    end

    # INITIAL GUESS;
    x = [0.0; 0.0; 0.0];
    
    # PARAMETERS;
    a = 10e-4;
    s = 0.5  ;
    ϵ = 1e-5 ;
    M = 1000 ;

    x = gradient_descent(a, s, ϵ, M, x, fun, true);
    println(x);

    close(file);
end

function load(filepath)
    file = open(filepath, "r");
    for line in eachline(file)
        row = parse.(Float64, split(line));
        push!(data, row);
        push!(u, row[1]);
        push!(v, row[2]);
        global N += 1;
    end
end

load(file_path)
main(file_path)

