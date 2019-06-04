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
        translate([servo_holder_x, servo_holder_y  + 30, min_thick]) {

cube([base_width, 50, min_thick]);
    
}
}

difference() {

    // servo holder
    translate([servo_holder_x, servo_holder_y, min_thick]) {
    
        // two arms
        translate([-2.8,servo_bottom_height - min_thick,0]) {
            cube([tab_width + 5, min_thick * 1.5 , arm_height]);
        }
        translate([servo_body_width + tab_width + 3,servo_bottom_height-min_thick,0]) {
            cube([tab_width + 10, min_thick * 1.5 , arm_height]);
        }
        
        //base
        translate([0,30,0]) {
            cube([servo_body_width + 2* tab_width + 13, 5 , servo_elevation]);
        }
    }

    // holes on the arms
    translate([servo_holder_x, servo_holder_y, min_thick]) {
        translate([2.5, servo_bottom_height-min_thick-1, servo_elevation+4.25 ]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick +4, 2.07,2.07, $fn=10);
            }
        }
        
        translate([2.5, servo_bottom_height-min_thick-1, servo_elevation+16]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick +4, 2.07,2.07, $fn=10);
            }
        }
        translate([2.5 + hole_dist + 5, servo_bottom_height-min_thick-1, servo_elevation+4.25]) {
            rotate([-90, 0, 0]){
                cylinder(min_thick + 4, 2.07,2.07, $fn=10);
            }
        }
        translate([2.5 + hole_dist + 5, servo_bottom_height-min_thick-1, servo_elevation+16]) {
            rotate([-90, 0, 0]) {
                cylinder(min_thick + 4, 2.07, 2.07, $fn=10);
            }
        }
    }
    
}

// pot holder
pot_holder_width = 30;
difference() {
    
    translate([servo_holder_x-1 + 4, servo_holder_y + servo_bottom_height + gap, min_thick]) {
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
    

    
    translate([servo_holder_x + tab_width + 14, servo_holder_y + servo_bottom_height + gap -1, 
              servo_elevation + .5 * servo_body_depth + min_thick]) {
                  
        //pot hole
        rotate([-90, 0, 0]){
            cylinder(min_thick + 2, pot_hole,pot_hole, $fn=20);
        }
        
        // tab slots
         translate([-pot_tab_gap/2, min_thick/2.0 +.5, 0]) {
        cube([ 1.5, min_thick +2, pot_tab_width], true);
         }
          translate([pot_tab_gap/2, min_thick/2.0 +.5, 0]) {
        cube([ 1.5, min_thick +2, pot_tab_width], true);
         }
    }
  
   
    
}
