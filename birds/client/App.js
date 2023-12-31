import React, { useState } from "react";
import { StyleSheet, Text, TouchableOpacity, View } from "react-native";


const App = () => {
  return (
    <View style={styles.container}>
      <Text style = {styles.infoPage}>Black birds</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    marginTop: 8,
    backgroundColor: "black",
    alignItems: "center",
    justifyContent:"center",
  },
  infoPage:{
    color:'white',
  },
});

export default App;
