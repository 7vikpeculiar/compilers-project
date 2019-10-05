% Mask File -> b
% Ppt Data -> basin_daily_ppt.mat
% Discharge Location -> discharge/
% Discharge Values -> discharge/asin.mat
% Lat-long -> latlong_lim
% DEM File -> DEM_clipped.tif
filepath='DEM_clipped.tif';
%Read GTiff
[image,geo]=geotiffread(filepath);
%Read info
info=geotiffinfo(filepath);
[m,n] = size(image);%%
flow_output = get_flow_map(image);%%
accum_output = get_accum_map(flow_output);%%
figure%%
DEM =GRIDobj('DEM_clipped.tif');
FD = FLOWobj(DEM,'multi');%%
help FLOWobj%%
basin = load('basin.mat')
basin%%
lat_long = load('latlong_limit.mat')
a = geotiffinfo('DEM_clipped.tif')
basin.rev_new%%
function [flow_map]  = get_flow_map(image)
padded_image = conv2(image,[0,0,0;0,1,0;0,0,0]);
[m,n] = size(padded_image);
flow_map = zeros(size(padded_image));
for i = 2:m-1
    for j = 2:n-1
        if padded_image(i,j) == 0
            continue
        end
        vect = [padded_image(i-1,j), ...
            padded_image(i-1,j+1), ...
            padded_image(i,j+1),...
            padded_image(i+1,j+1), ...
            padded_image(i+1,j), ...
            padded_image(i+1,j-1), ...
            padded_image(i,j-1), ...
            padded_image(i-1,j-1)];
        vect = -vect + padded_image(i,j);
        [~, idx] = max(vect);
        flow_map(i,j) = idx;
    end
end
flow_map = flow_map(2:m-1,2:n-1);
end

function [accum_map] = get_accum_map(flow_map)
dir_array = [-1,0; ...
            -1,+1; ...
            0,+1;...
            +1,+1; ...
            +1,0; ...
            +1,-1; ...
            0,-1; ...
            -1,-1];
padded_image = conv2(flow_map,[0,0,0;0,1,0;0,0,0]);
accum_map = zeros(size(padded_image));
[m,n] = size(padded_image);    
for i = 2:m-1
    for j = 2:n-1
            if padded_image(i,j) == 0
            continue        
            end
       tmp = dir_array(padded_image(i,j),:) + [i,j];
       new_index = [i,j]+dir_array(padded_image(i,j),:) ; 
       accum_map(new_index(1),new_index(2)) = 1+accum_map(new_index(1),new_index(2)) + accum_map(i,j);
    end
end
accum_map = accum_map(2:m-1,2:n-1);
end
