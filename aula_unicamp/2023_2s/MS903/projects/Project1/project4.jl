# Implementando gradiente com passo fixo.

function gradient_descent_fixed(ϵ::Float64, M::Int64, 
    x::Vector{Float64}, fun::Function, t::Float64   ,
    )
    k     = 0; # COUNTER
    f, ∇f = fun(x);
    μ     = infty_norm(∇f);
    x_ant = 0;
    ∇f_ant= 0;

    while( (μ >= ϵ) && (k < M) )
        x_ant  = x;
        ∇f_ant = ∇f;
        x      = x - t * ∇f;
        f, ∇f  = my_function(x);
        μ      = infty_norm(∇f);
        k      += 1;
    end

    return x;
end
#######################



# Definindo parâmetros:
ϵ = 10e-6;
M = 1000 ;
x = [0.0; 0.0];