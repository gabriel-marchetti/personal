using Pkg;
using ForwardDiff, Plots, Interact;
gr(size=(500,300));

begin
    f(x) =  if x ≤ 1
                (x-1)*(x-1);
            elseif x ≤ 5
                (x-1)*0.5;
            else
                sqrt(x-1);
            end
    a, b = -1, 7;
    plot(f, a, b);
end

function random_uni(f, a, b)
    c = a + (b - a) * rand();

    for k = 1:10
        d = a + (b-a)*rand();
        if c > d
            c, d = d, c;  
        end

        # Faço o método...
        if f(c) < f(d)
            a, b, c = a, d, c;
        else
            a, b, c = c, b, d;
        end
    end

    return c;
end

function random_uni_plot(p, f, a, b)
    c = a + (b - a) * rand();
    scatter!(p, [a, b], [f(a), f(b)], c=:red, ms=3);
    scatter(p, [c], [f(c)], c=:blue, ms=3);

    anim = @animate for i = 1:10
        d = a + (b-a)*rand();
        if c > d
            c, d = d, c;  
        end

        # Faço o método...
        if f(c) < f(d)
            a, b, c = a, d, c;
        else
            a, b, c = c, b, d;
        end
        scatter(p, [c], [f(c)], c=:blue, ms=3);
    end

    return c, anim;
end

p = plot(f, -5, 5, leg=false)
c, anim = random_uni_plot(p, f, -5, 5);
anim
gif(anim, "anim.mp4", fps=1)

random_uni(f, a, b)

p = plot(f, a, b, leg=false);
random_uni_plot(p, f, a, b)
p

function random_uni_error(f, a, b)
    c = a + (b - a) * rand();
    ϵ = 1e-4;
    k = 0;
    while( b - a ≥ ϵ )
        d = a + (b - a) * rand();
        if c > d;
            c, d = d, c;
        end

        if f(c) < f(d)
            a, b, c = a, d, c;
        else
            a, b, c = c, b, d;
        end
        k = k + 1;
    end

    return c, k
end

c, k = random_uni_error(f, a, b)

g(x) = sin(π * x) * 5 + x*x;
p = plot(g, -5, 5, leg=false);
random_uni_plot(p, g, -5, 5)
p
