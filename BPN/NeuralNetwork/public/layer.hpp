#ifndef NEURALNETWORK_PUBLIC_LAYER_HPP
#define NEURALNETWORK_PUBLIC_LAYER_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

#include <NeuralNetwork/public/activationFunction.hpp>

namespace NeuralNetwork_ns
{

	namespace Layer
	{

		class ILayer
		{
		public:
			ILayer(NeuralNetwork_ns::numeric nOutput, NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction);
			ILayer(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction);

			void SetInputCount(NeuralNetwork_ns::numeric InputCount);
			NeuralNetwork_ns::numeric GetInputCount();

			void SetOutputCount(NeuralNetwork_ns::numeric OutputCount);
			NeuralNetwork_ns::numeric GetOutputCount();

			void SetLayerWeights(NeuralNetwork_ns::layer_weights_t Weights);
			NeuralNetwork_ns::layer_weights_t GetLayerWeights();

			void SetLayerBiases(NeuralNetwork_ns::layer_biases_t Biases);
			NeuralNetwork_ns::layer_biases_t GetLayerBiases();

			void SetLayerActivationFunction(NeuralNetwork_ns::ActivationFunction::IActivationFunction ActivationFunction);
			NeuralNetwork_ns::ActivationFunction::IActivationFunction GetLayerActivationFunction();

			void InvalidateMatrix();
			void RandomizeMatrix();

			virtual void CalculateInducedLocalField(NeuralNetwork_ns::layer_input_t);
			NeuralNetwork_ns::layer_output_t ReadInducedLocalField();

			virtual void CalculateOutput(NeuralNetwork_ns::layer_input_t);
			NeuralNetwork_ns::layer_output_t ReadOutput();

			void SetPreviousLayer(ILayer* layer);
			ILayer* GetPreviousLayer();

			void SetNextLayer(ILayer* layer);
			ILayer* GetNextLayer();

		protected:
			NeuralNetwork_ns::layer_output_t m_InducedLocalField;
			NeuralNetwork_ns::layer_output_t m_Activation;

		private:
			NeuralNetwork_ns::numeric m_nInputs;
			NeuralNetwork_ns::numeric m_nOutputs;
			
			NeuralNetwork_ns::layer_weights_t m_Weights;
			NeuralNetwork_ns::layer_biases_t m_Bias;

			ILayer* m_PreviousLayer;
			ILayer* m_NextLayer;

			NeuralNetwork_ns::ActivationFunction::IActivationFunction m_ActivationFunction;
		};

		class InputLayer : public ILayer
		{
		public:
			void CalculateInducedLocalField(NeuralNetwork_ns::layer_input_t input) override;
			void CalculateOutput(NeuralNetwork_ns::layer_input_t input) override;
		};

		class DenseLayer : public ILayer
		{

		};

		class OutputLayer : public ILayer
		{

		};

	}

}

#endif // NEURALNETWORK_PUBLIC_LAYER_HPP