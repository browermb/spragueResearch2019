servo_body_width = 40.17;
servo_body_depth = 20.25;
servo_bottom_height = 40.5; 
servo_elevation = 13;

servo_holder_x = 3;
servo_holder_y = 0;
pot_hole = 5.3;
tab_width = 3.8;
gap = 38; 
hole_dist = servo_body_width + 4;
pot_tab_gap = 25;
pot_tab_width = 3.1;

arm_height = servo_body_depth + servo_elevation ;
min_thick = 5;

base_width = servo_body_width +23.5;
base_length = servo_body_width  + 43;

// base
difference() {
    
cube([base_width, base_length, min_thick]);
    
    union() {
    translate([base_width / 2.0, base_length / 2 + 8, 0])
    cylinder(min_thick +10, 2,2, true, $fn=10);
        
         translate([base_width / 2.0, base_length / 2 + 25, 0])
    cylinder(min_thick +10, 2,2, true, $fn=10);
    }
}

difference() {

    // servo holder
    translate([servo_holder_x, servo_holder_y, min_thick]) {
    
        // two arms
        translate([-2.8,servo_bottom_height - min_thick,0]) {
            cube([tab_width + 5, min_thick * 1.5 , arm_height]);
        }
        translate([servo_body_width + tab_width + 2.5,servo_bottom_height-min_thick,0]) {
            cube([tab_width + 10, min_thick * 1.5 , arm_height]);
        }
        
        //base
        translate([0,0,0]) {
            cube([servo_body_width + 2* tab_width + 13, servo_bottom_height , servo_elevation]);
        }
    }

    // holes on the arms
    translate([servo_holder_x, servo_holder_y, min_thick]) {
        translate([2.3, servo_bottom_height-min_thick-1, servo_elevation+4.25 ]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick +4, 2.07,2.07, $fn=10);
            }
        }
        
        translate([2.3, servo_bottom_height-min_thick-1, servo_elevation+15.5]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick +4, 2.07,2.07, $fn=10);
            }
        }
        translate([2.4 + hole_dist + 5, servo_bottom_height-min_thick-1, servo_elevation+4.25]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick + 4, 2.07,2.07, $fn=10);
            }
        }
        translate([2.4 + hole_dist + 5, servo_bottom_height-min_thick-1, servo_elevation+15.5]) {
            rotate([-90, 0, 0]) {
                cylinder(min_thick + 4, 2.07, 2.07, $fn=10);
            }
        }
    }
    
}

// pot holder
pot_holder_width = 30;
difference() {
    
    translate([servo_holder_x-1, servo_holder_y + servo_bottom_height + gap, min_thick]) {
        cube([pot_holder_width, min_thick, servo_elevation+20]);
        
        // supports
        translate([0, -4,0])
        difference(){
            cube([min_thick, 8, 20]);
            translate([-.1, 0, 0]) rotate([75, 0, 0]) cube([min_thick+1, 40, 20]);
        }
        translate([pot_holder_width-min_thick, -4,0])
        difference(){
            cube([min_thick, 8, 20]);
            translate([-.1, 0, 0]) rotate([75, 0, 0]) cube([min_thick+1, 40, 20]);
        }
    }
    


    translate([18.4, servo_holder_y + servo_bottom_height + gap -1, 
              servo_elevation + .5 * servo_body_depth + min_thick]) {
                  
        //pot hole
        rotate([-90, 0, 0]){
            cylinder(min_thick + 2, 4.65,4.65, $fn=20);
        
    
        // tab slot
          translate([10.6, 1.15, 0]) {
            cylinder(min_thick + 2, 1.75,1.75, $fn=20);
          }
    
        }
    }
    
}
  
   
    

